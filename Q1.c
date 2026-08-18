#include <stdio.h>
#include <stdlib.h>

// Proper input representation mapping colours to integers
typedef enum {
    RED = 0,
    BLUE = 1,
    YELLOW = 2
} Colour;

// Structure representing the pair of items
typedef struct {
    int number;
    Colour colour;
} Item;

// O(n) Stable Counting Sort Algorithm
void stableColourSort(Item arr[], int n) {
    Item* output = (Item*)malloc(n * sizeof(Item));
    int count[3] = {0, 0, 0};

    // Frequency Count
    for (int i = 0; i < n; i++) {
        count[arr[i].colour]++;
    }

    // Cumulative Count to find endpoints
    count[1] += count[0];
    count[2] += count[1];

    // Stable Placement (Traversing right to left ensures stability)
    for (int i = n - 1; i >= 0; i--) {
        Colour c = arr[i].colour;
        output[count[c] - 1] = arr[i];
        count[c]--;
    }

    // Copy sorted array back to original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

int main() {
    int n;
    
    printf("Enter the number of pairs: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Item* items = (Item*)malloc(n * sizeof(Item));
    
    printf("Enter %d items as '<number> <colour_code>' (0 = Red, 1 = Blue, 2 = Yellow):\n", n);
    for (int i = 0; i < n; i++) {
        int colour_val;
        scanf("%d %d", &items[i].number, &colour_val);
        items[i].colour = (Colour)colour_val;
    }

    // Execute the stable sorting algorithm
    stableColourSort(items, n);

    // Print validated output
    printf("\nSorted Output (Reds -> Blues -> Yellows):\n");
    for (int i = 0; i < n; i++) {
        const char* colourName = (items[i].colour == RED) ? "Red" :
                                 (items[i].colour == BLUE) ? "Blue" : "Yellow";
        printf("Number: %d | Colour: %s\n", items[i].number, colourName);
    }

    free(items);
    return 0;
}