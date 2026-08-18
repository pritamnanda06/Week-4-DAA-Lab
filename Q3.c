#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Standard iterative Binary Search
bool binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// Recursive helper to fix k-1 elements and binary search the last one
bool kSumHelper(int arr[], int n, int k, int target, int start_index) {
    // Base Case: When only 1 element is left to find, use Binary Search
    if (k == 1) {
        return binarySearch(arr, start_index, n - 1, target);
    }
    
    // Recursive Case: Fix one element and reduce k by 1
    for (int i = start_index; i <= n - k; i++) {
        if (kSumHelper(arr, n, k - 1, target - arr[i], i + 1)) {
            return true;
        }
    }
    
    return false;
}

// Main Wrapper Function
bool hasKSum(int arr[], int n, int k, int target) {
    if (n < k || k < 1) return false;
    
    // Step 1: Sort the array which takes O(n log n)
    qsort(arr, n, sizeof(int), compare);
    
    // Step 2 & 3: Fix k-1 elements and binary search the last
    return kSumHelper(arr, n, k, target, 0);
}

int main() {
    int n, k, target;

    // Take user input for the size of the set
    printf("Enter the number of elements in the set (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }

    int *S = (int*)malloc(n * sizeof(int));
    if (S == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Take user input for the elements of set S
    printf("Enter %d integers for set S:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    // Take user input for k and target sum T
    printf("Enter the number of elements to sum (k): ");
    scanf("%d", &k);

    printf("Enter the target sum (T): ");
    scanf("%d", &target);

    // Validate the algorithm with the user inputs
    printf("\n--- Results ---\n");
    printf("Set S: { ");
    for(int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("}\n");
    printf("Target Sum (T): %d\n", target);
    printf("Number of elements (k): %d\n\n", k);

    if (hasKSum(S, n, k, target)) {
        printf("Result: YES, there are %d elements in S that add up to %d.\n", k, target);
    } else {
        printf("Result: NO, there are no %d elements in S that add up to %d.\n", k, target);
    }

    // Free dynamically allocated memory
    free(S);

    return 0;
}