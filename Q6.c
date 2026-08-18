#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coord;  /* the coordinate at which the event occurs        */
    int type;   /* +1 for a start (left endpoint), -1 for an end     */
                /* (right endpoint)                                  */
} Event;

/*
 * Comparator for qsort: sort events by coordinate ascending.
 * If coordinates are equal, start events (+1) come before end events (-1),
 * so a point where one interval ends and another begins is counted as
 * covered by both.
 */
int compareEvents(const void *a, const void *b) {
    const Event *e1 = (const Event *)a;
    const Event *e2 = (const Event *)b;

    if (e1->coord != e2->coord) {
        return e1->coord - e2->coord;
    }
    /* Same coordinate: start (+1) before end (-1) -> descending type */
    return e2->type - e1->type;
}

int main(void) {
    int n;

    printf("Enter number of intervals (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *left  = (int *)malloc(n * sizeof(int));
    int *right = (int *)malloc(n * sizeof(int));
    if (!left || !right) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter left and right endpoint for each of the %d intervals:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Interval %d (left right): ", i + 1);
        scanf("%d %d", &left[i], &right[i]);

        if (right[i] < left[i]) {
            printf("Invalid: right endpoint must not be less than left.\n");
            free(left);
            free(right);
            return 1;
        }
    }

    /* Build the array of 2n events */
    int totalEvents = 2 * n;
    Event *events = (Event *)malloc(totalEvents * sizeof(Event));
    if (!events) {
        printf("Memory allocation failed.\n");
        free(left);
        free(right);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        events[2 * i].coord     = left[i];
        events[2 * i].type      = +1;   /* start event */
        events[2 * i + 1].coord = right[i];
        events[2 * i + 1].type  = -1;   /* end event   */
    }

    /* Sort events by coordinate (start before end on ties) -> O(n log n) */
    qsort(events, totalEvents, sizeof(Event), compareEvents);

    /* Sweep through events, tracking running count and its peak -> O(n) */
    int count = 0;
    int maxCount = 0;
    int peakPoint = events[0].coord;

    for (int i = 0; i < totalEvents; i++) {
        count += events[i].type;
        if (count > maxCount) {
            maxCount = count;
            peakPoint = events[i].coord;
        }
    }

    printf("\nMaximum number of intervals covering a single point: %d\n", maxCount);
    printf("One such point is: %d\n", peakPoint);

    free(left);
    free(right);
    free(events);
    return 0;
}