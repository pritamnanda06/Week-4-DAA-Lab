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

Space Complexity:$O(1)$ if an in-place sorting algorithm (like Heap Sort) is used.

$O(n)$ if an out-of-place algorithm (like Merge Sort) is used.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


For Q3
------

Step-by-Step Algorithm

Sort the Set: Sort the set $S$ of $n$ integers in ascending order using an efficient algorithm like Merge Sort or Heap Sort.

Iterate to Fix $k-1$ Elements: Use $k-1$ nested loops to systematically select the first $k-1$ elements to test.

The outermost loop picks the first element at index $i_1$.

The second loop picks the second element at index $i_2$ (where $i_2 > i_1$).

This nesting continues down to the $(k-1)^{th}$ loop picking an element at index $i_{k-1}$.

Calculate the Complement: Inside the innermost loop, calculate the sum of the currently selected $k-1$ elements. Subtract this partial sum from the target $T$  to find the exact value needed for the $k^{th}$ element (the complement). 

$$
Complement = T - (S[i_1] + S[i_2] + \dots + S[i_{k-1}])
$$
                          

Binary Search for the Last Element: Perform a Binary Search strictly on the remaining, unselected portion of the sorted array (from index $i_{k-1} + 1$ to $n - 1$) to look for the calculated complement.

Evaluate Results:If the Binary Search finds the complement, a valid set of $k$ integers exists; return True immediately.

If all nested loops complete their iterations without the Binary Search finding a complement, return False.

Complexity Analysis

Time Complexity: * Sorting the array $S$ initially takes $O(n \log n)$ time.

The $k-1$ nested loops will execute $O(n^{k-1})$ times in the worst-case scenario.Inside the innermost loop, the Binary Search takes $O(\log n)$ time.

Multiplying the nested loops by the search time gives $O(n^{k-1} \log n)$ for the searching phase.Total Time Complexity: $O(n \log n) + O(n^{k-1} \log n) = O(n^{k-1} \log n)$, strictly satisfying the problem's requirements. 

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


For Q4
------


### Algorithm
1. Build an array of 2n events: for each person i, create an entry event
   at a_i and an exit event at b_i.
2. Sort the events by time — O(n log n).
3. Sweep through the sorted events left to right, maintaining a counter:
   - on an entry event, increment the counter
   - on an exit event, decrement the counter
4. Track the maximum counter value seen and the time at which it occurred.
5. Return that time (and the max count) as the answer.

### Complexity
- Sorting: O(n log n)
- Single linear sweep: O(n)
- Total: O(n log n)

### Note on the "no ties" assumption
Since all 2n entry/exit times are distinct, there's no ambiguity about
which event "happens first" at the same instant — every event has a
strict, well-defined order, so the sweep is unambiguous. (If ties were
allowed, you'd need a tie-breaking rule — typically process all entry
events at a given time before exit events at that same time, or vice
versa, depending on whether the boundary instant should count as
overlapping.)
