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


For Q2
------

Step-by-Step Algorithm

Sort One Set: Choose one of the sets, for example, $S_2$, and sort it in ascending order using an efficient sorting algorithm like Merge Sort or Heap Sort.

Iterate Through the Other Set: Loop through each element $a$ in the unsorted set $S_1$.

Calculate the Complement: For each element $a$ in $S_1$, calculate its required complement $b$ such that $b = x - a$.

Binary Search: Use a Binary Search algorithm to look for the complement $b$ within the sorted set $S_2$.

Evaluate Results:If the Binary Search finds $b$ in $S_2$, return True immediately (a valid pair exists).

If the loop finishes checking all elements in $S_1$ without the Binary Search finding a single complement, return False (no such pair exists).

Complexity Analysis

Time Complexity:

Sorting $S_2$ takes $O(n \log n)$ time.Iterating through $S_1$ takes $n$ steps. Inside the loop, the Binary Search on $S_2$ takes $O(\log n)$ time.This combined searching phase takes $O(n \log n)$ time.

Total Time Complexity: $O(n \log n) + O(n \log n) = O(n \log n)$, which strictly satisfies the problem's requirements.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Space Complexity:$O(1)$ if an in-place sorting algorithm (like Heap Sort) is used.

$O(n)$ if an out-of-place algorithm (like Merge Sort) is used.
