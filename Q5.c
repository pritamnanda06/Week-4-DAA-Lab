#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

/* Comparator for qsort: sort intervals by start value ascending. */
int compareIntervals(const void *a, const void *b) {
    const Interval *i1 = (const Interval *)a;
    const Interval *i2 = (const Interval *)b;
    return i1->start - i2->start;
}

int main(void) {
    int n;

    printf("Enter number of intervals (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Interval *intervals = (Interval *)malloc(n * sizeof(Interval));
    if (!intervals) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter start and end for each of the %d intervals:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Interval %d (start end): ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].end);

        if (intervals[i].end < intervals[i].start) {
            printf("Invalid: end must not be less than start.\n");
            free(intervals);
            return 1;
        }
    }

    /* Sort intervals by start value -> O(n log n) */
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    /* Result array can hold at most n merged intervals */
    Interval *merged = (Interval *)malloc(n * sizeof(Interval));
    if (!merged) {
        printf("Memory allocation failed.\n");
        free(intervals);
        return 1;
    }

    int mergedCount = 0;

    /* Start with the first sorted interval as the "current" interval */
    Interval current = intervals[0];

    /* Single linear sweep -> O(n) */
    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= current.end) {
            /* Overlaps or touches: extend current interval's end */
            if (intervals[i].end > current.end) {
                current.end = intervals[i].end;
            }
        } else {
            /* No overlap: finalize current, start a new one */
            merged[mergedCount++] = current;
            current = intervals[i];
        }
    }
    /* Add the last current interval */
    merged[mergedCount++] = current;

    printf("\nMerged intervals:\n");
    for (int i = 0; i < mergedCount; i++) {
        printf("(%d, %d)\n", merged[i].start, merged[i].end);
    }

    free(intervals);
    free(merged);
    return 0;
}