For Q1
------

Core Strategy: Stable Counting Sort

Since there are only three distinct colours, Counting Sort achieves linear time $O(n)$. Stability is guaranteed by performing a backward traversal (right to left) during the placement phase.
Step-by-Step Algorithm
Input Representation: Represent each item as a structure containing a number and a colour (mapped as RED = 0, BLUE = 1, YELLOW = 2).
Frequency Count: Traverse the input array of size $n$ to count the frequency of each colour and store them in a count array of size 3.
Cumulative Count: Update the count array with cumulative sums to determine the ending boundary positions for each colour group.
Stable Placement: Allocate an auxiliary output array of size $n$. Traverse the input array from right to left (index $n-1$ down to $0$), placing each item into its correct position in the output array and decrementing its count to preserve the relative order of items with identical colours.
Copy Back: Copy the sorted elements from the output array back into the original array.
Complexity Analysis

Time Complexity: $O(n)$ (Frequency counting, cumulative sums, and right-to-left placement run in linear time with respect to $n$, as the number of colours $k=3$ is a constant).
Space Complexity: $O(n)$ (Requires an auxiliary output array of size $n$ and a fixed-size count array of size 3).

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
