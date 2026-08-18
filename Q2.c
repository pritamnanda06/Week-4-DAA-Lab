#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Standard Binary Search implementation
bool binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return true;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// O(n log n) algorithm to find if a pair exists that adds up to x
bool findPairWithSum(int S1[], int S2[], int n, int x) {
    // Step 1: Sort S2. qsort average time complexity is O(n log n)
    qsort(S2, n, sizeof(int), compare);
    
    // Step 2 & 3: Iterate through S1 and calculate the complement
    for (int i = 0; i < n; i++) {
        int complement = x - S1[i];
        
        // Step 4 & 5: Binary search for the complement in the sorted S2
        if (binarySearch(S2, n, complement)) {
            printf("Pair found: %d (from S1) + %d (from S2) = %d\n", S1[i], complement, x);
            return true; 
        }
    }
    
    return false;
}

int main() {
    int n, x;
    
    printf("Enter the size of the sets (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }
    
    int *S1 = (int *)malloc(n * sizeof(int));
    int *S2 = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d elements for Set S1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S1[i]);
    }
    
    printf("Enter %d elements for Set S2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S2[i]);
    }
    
    printf("Enter the target sum (x): ");
    scanf("%d", &x);
    
    // Execute the algorithm
    bool found = findPairWithSum(S1, S2, n, x);
    
    if (!found) {
        printf("No pair exists that adds up to %d.\n", x);
    }
    
    // Free allocated memory
    free(S1);
    free(S2);
    
    return 0;
}