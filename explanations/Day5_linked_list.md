Problem Description (Day_5_Linked_List)
This problem requires checking whether a singly linked list is a palindrome—meaning it reads the same forward and backward.

📌 Example Cases:
✅ 1 → 2 → 2 → 1 → Palindrome.
❌ 1 → 2 → 3 → Not a Palindrome.

Approach & Solution Explanation -
Since a linked list doesn’t allow reverse traversal like an array, we need a strategy to efficiently compare elements.

Step 1:- Find the Middle Using Fast & Slow Pointer method.
The `sp` pointer advances one step at a time, while the `fp` pointer moves two steps in each iteration. As a result, `fp` reaches the end of the list much faster than `sp`. When `fp` reaches the final node or goes beyond it, `sp` will have arrived at the middle of the linked list, effectively dividing it into two halves.

Step 2:- Reverse the Second Half of the List.
Starting from sp->next, we reverse the remaining nodes so they point backward instead of forward.

Step 3:- Compare Both Halves.
To determine if the linked list is a palindrome, we compare the first half of the original list with the second half after reversal, checking each node's value one by one. If all corresponding pairs match, the list maintains its symmetry and qualifies as a palindrome. However, if any values differ at any point in the comparison, the sequence is not a palindrome.

🚀 Why This Works Efficiently?
✅ O(n) time complexity – We traverse the list three times (finding middle, reversing, comparing).
✅ O(1) extra space – We reverse in-place without using extra arrays