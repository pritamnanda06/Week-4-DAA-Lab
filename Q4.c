#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;   /* the time at which the event occurs           */
    int type;   /* +1 for entry event, -1 for exit event         */
} Event;

/* Comparator for qsort: sort events by time ascending.
   Since all 2n times are distinct (per problem assumption),
   there are no ties to break. */
int compareEvents(const void *a, const void *b) {
    const Event *e1 = (const Event *)a;
    const Event *e2 = (const Event *)b;
    return e1->time - e2->time;
}

int main(void) {
    int n;

    printf("Enter number of persons (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *entry = (int *)malloc(n * sizeof(int));
    int *exitT = (int *)malloc(n * sizeof(int));
    if (!entry || !exitT) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter entry time and exit time for each of the %d persons:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Person %d (entry exit): ", i + 1);
        scanf("%d %d", &entry[i], &exitT[i]);

        if (exitT[i] <= entry[i]) {
            printf("Invalid: exit time must be greater than entry time.\n");
            free(entry);
            free(exitT);
            return 1;
        }
    }

    /* Build the array of 2n events */
    int totalEvents = 2 * n;
    Event *events = (Event *)malloc(totalEvents * sizeof(Event));
    if (!events) {
        printf("Memory allocation failed.\n");
        free(entry);
        free(exitT);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        events[2 * i].time     = entry[i];
        events[2 * i].type     = +1;   /* entry event */
        events[2 * i + 1].time = exitT[i];
        events[2 * i + 1].type = -1;   /* exit event  */
    }

    /* Sort events by time -> O(n log n) */
    qsort(events, totalEvents, sizeof(Event), compareEvents);

    /* Sweep through events, tracking running count and its peak -> O(n) */
    int count = 0;
    int maxCount = 0;
    int peakTime = events[0].time;

    for (int i = 0; i < totalEvents; i++) {
        count += events[i].type;
        if (count > maxCount) {
            maxCount = count;
            peakTime = events[i].time;
        }
    }

    printf("\nMaximum number of people present simultaneously: %d\n", maxCount);
    printf("This peak first occurs at time: %d\n", peakTime);

    free(entry);
    free(exitT);
    free(events);
    return 0;
}