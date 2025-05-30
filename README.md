Below is an enhanced explanation for the "Push Swap" project. 
==> It details the sorting algorithms implemented in the code and describes how they work to sort a stack of integers using two stacks (A and B) and a limited set of operations.

==> Push Swap is a project that requires sorting a stack of integers using a restricted set of operations and an auxiliary stack. 
The objective is to sort stack A in ascending order, with the smallest number at the top, in the fewest moves possible, using stack B as a temporary holding space.

============================================================================================================================================================================================================
Operations
The allowed operations are:

sa: Swap the first two elements at the top of stack A.
sb: Swap the first two elements at the top of stack B.
ss: Perform sa and sb at the same time.
pa: Push the top element of stack B to stack A.
pb: Push the top element of stack A to stack B.
ra: Rotate stack A (shift all elements up by one; the first element becomes the last).
rb: Rotate stack B (same as ra but for stack B).
rr: Perform ra and rb simultaneously.
rra: Reverse rotate stack A (shift all elements down by one; the last element becomes the first).
rrb: Reverse rotate stack B (same as rra but for stack B).
rrr: Perform rra and rrb simultaneously.

============================================================================================================================================================================================================
Sorting Algorithms
==> The code implements tailored sorting strategies depending on the number of elements in the stack. 

Below is an explanation of each algorithm and how it works.

1. Sorting Stacks of Size 3 (sort_3)
For stacks with exactly 3 elements, the algorithm uses a straightforward method to sort them efficiently with minimal operations.


============================================================================================================================================================================================================
How It Works:

==> The function evaluates the current order of the three elements by checking specific conditions (e.g., whether the first element is greater than the second, the second greater than the third, etc.).
Based on these conditions, it applies a combination of operations (sa, ra, or rra) to sort the stack. For example:
If the order is [3, 1, 2], it might use sa (to get [1, 3, 2]) followed by ra (to get [3, 2, 1]) and then sa again (to get [2, 1, 3]), adjusting as needed.
The goal is to achieve [1, 2, 3] (smallest at the top).
Key Feature: It handles all possible permutations of three elements with predefined operation sequences, ensuring efficiency.
2. Sorting Stacks of Size 4 (sort_4)
For stacks with 4 elements, the algorithm builds on the sort_3 function by isolating one element temporarily.


============================================================================================================================================================================================================
How It Works:

==> Find the Smallest Element: Identify the smallest number in stack A.
Push to Stack B: Move this element to stack B using pb. For example, if the stack is [4, 2, 3, 1], push 1 to stack B, leaving [4, 2, 3] in stack A.
Sort Remaining Three: Use sort_3 to sort the remaining three elements in stack A (e.g., [4, 2, 3] becomes [2, 3, 4]).
Push Back: Move the smallest element back from stack B to stack A using pa, resulting in [1, 2, 3, 4].
Key Feature: Reduces the problem to a smaller, already-solved case (sorting 3 elements) while maintaining the overall sorted order.
3. Sorting Stacks of Size 5 (sort_3_4_5)
For stacks with 5 elements, the approach extends the sort_4 logic.


============================================================================================================================================================================================================
How It Works:

==> Push the Smallest Element: Identify the smallest element in stack A and push it to stack B with pb. For instance, [5, 2, 4, 1, 3] becomes [5, 2, 4, 3] in A and [1] in B.
Sort Remaining Four: Call sort_4 to sort the four elements left in stack A (e.g., [5, 2, 4, 3] becomes [2, 3, 4, 5]).
Push Back: Use pa to bring the smallest element back to stack A, yielding [1, 2, 3, 4, 5].
Key Feature: Iteratively reduces the stack size, leveraging previously defined functions to maintain simplicity and efficiency.
4. Sorting Larger Stacks (hossni_sorting)
For stacks with more than 5 elements, a sophisticated chunk-based algorithm is used to handle larger datasets efficiently.


============================================================================================================================================================================================================
How It Works:

Determine Chunk Size:
For stacks with ≤ 100 elements, the chunk size is 20.
For stacks with > 100 elements, the chunk size is 33.
This size dictates how many elements are processed at a time.
Push Elements to Stack B in Chunks:
==> Elements are assigned indexes based on their sorted position.
The algorithm pushes elements from stack A to stack B in chunks:
If an element’s index is within the current chunk range (e.g., 0 to 20), it’s pushed to stack B with pb.
If it’s in the next chunk range, it’s pushed and then rotated (rb) to maintain a semi-sorted order in stack B.
Rotations (ra or rra) are optimized based on the element’s position in stack A to minimize moves.
Example: For [7, 2, 9, 1, 5, 3], it might push 1 and 2 to stack B, rotating as needed, until all elements are in B.
Push Back to Stack A:
==> Once all elements are in stack B, the algorithm repeatedly:
Finds the maximum element in stack B.
Moves it to the top using the fewest rotations (rb or rrb).
Pushes it to stack A with pa.
This continues until stack B is empty, leaving stack A sorted (e.g., [1, 2, 3, 5, 7, 9]).
Key Feature: Breaks the problem into manageable chunks, ensuring scalability while optimizing operation count.

============================================================================================================================================================================================================
Error Handling
The program validates input by checking for:

Duplicate numbers.
Non-numeric values or integers outside the valid range.
If an error is detected, it prints "Error" to stderr and exits.
