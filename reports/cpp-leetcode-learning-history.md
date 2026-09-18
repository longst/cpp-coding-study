# C++ and LeetCode Learning History

## Executive summary

This record contains **37 distinct LeetCode problems** studied from Palindrome
Number through Number of 1 Bits. The count represents unique problem statements,
This record contains **31 distinct LeetCode problems** studied from Palindrome
Number through Add Two Numbers. The count represents unique problem statements,
not the number of drafts, solution revisions, code snippets, or general C++
topics discussed.

The learning path moved from basic indexing and string conversion into reusable
patterns: two pointers, write indices, stacks, binary search, linked-list
splicing, recursion on trees, dynamic programming, hash-based lookup, XOR,
Floyd's cycle detection, digit-by-digit arithmetic, sliding windows, row-by-row
simulation, Boyer-Moore voting, base conversion in both directions, and
foundational bit manipulation. The clearest progress is the shift from trying
to manipulate examples directly toward maintaining an invariant: "everything
before `writeIndex` is valid," "the stack contains unmatched openings," "the
window set has no duplicate characters," "the binary-search answer remains in
`[left, right)`," or "the recursive function returns the answer for this
subtree."
Floyd's cycle detection, and digit-by-digit arithmetic. The clearest progress is
the shift from trying to manipulate examples directly toward maintaining an
invariant: "everything before `writeIndex` is valid," "the stack contains
unmatched openings," "the binary-search answer remains in `[left, right)`," or
"the recursive function returns the answer for this subtree."

The most persistent difficulties were not a lack of algorithm ideas, but
implementation correctness:

- keeping indices inside bounds, especially around `size() - 1`;
- distinguishing a node pointer, a node object, and a node's `val`;
- checking for `nullptr` before dereferencing;
- advancing every pointer on every intended path;
- defining recursion by an exact base case and returning recursive results;
- preserving problem requirements such as in-place or constant-space behavior;
- carrying state correctly across digit-by-digit arithmetic;
- distinguishing assignment (`=`) from equality (`==`) in conditions;
- initializing state before reading it and keeping loop variables consistent;
- separating container allocation from allocation of each element's contents;
- ordering dependent operations correctly, especially shifts and bit insertion;
- handling edge cases and syntax punctuation before tracing the algorithm.
- carrying state correctly across digit-by-digit arithmetic.

Early brute-force approaches are not automatically wrong. For example,
checking every buy/sell pair for Best Time to Buy and Sell Stock is logically
correct, but it misses the desired linear-time pattern. Similarly, a set or
sorting can compute Single Number, but violates the constant-extra-space and
linear-time target. These are requirement or performance gaps, not failures to
understand the mathematical result.

## Count and methodology

### Total

**37 distinct coding problems**
**31 distinct coding problems**

### What counts

A problem counts once when the learning history identifies a distinct
LeetCode-style problem statement. Multiple attempts, corrections, alternative
solutions, and later reviews of the same problem remain one entry.

### What does not count

The following were studied but do **not** increase the problem count:

- STL/container topics: `unordered_map`, `unordered_set`, `stack`, `queue`, and
  `priority_queue`;
- traversal concepts: binary-tree preorder, inorder, postorder, and level order;
- library and language topics: `std::reverse`, character conversion/filtering,
  pointer syntax, recursion, and sorting arrays;
- repeated revisions of an existing solution;
- example exercises such as generic character counting or sorting practice.

Binary Tree Preorder Traversal is counted because it is itself a distinct
problem. The other traversal orders remain supporting concepts.

### Evidence and scope

Repository notes and source files provide detailed direct evidence for the
first nine problems in the historical sequence (Palindrome Number through Plus
One, with Search Insert Position and Length of Last Word discussed in a
different order). The supplied learning-history inventory and subsequent
conversation extend the record through Number of 1 Bits. Later entries below
therefore describe the recorded approaches and mistakes conservatively; they do
not claim submission, acceptance, or completion outcomes that are not present
in the records.
different order). The supplied learning-history inventory extends the record
through Add Two Numbers. Later entries below therefore describe the recorded
approaches and mistakes conservatively; they do not claim submission,
acceptance, or completion outcomes that are not present in the records.

The existing `notes/session-summary.md` mentions "Contains duplicate," but that
item is not in the cross-checked distinct-problem inventory and has no dedicated
problem record. It is treated here as `unordered_set` practice rather than
silently increasing the verified total to 38.
silently increasing the verified total to 32.

## Categorized inventory

| Category | Count | Distinct problems |
|---|---:|---|
| Arrays, strings, binary search, and simulation | 13 | Palindrome Number; Remove Duplicates from Sorted Array; Remove Element; Find the Index of the First Occurrence in a String; Length of Last Word; Search Insert Position; Plus One; Merge Sorted Array; Longest Common Prefix; Best Time to Buy and Sell Stock; Valid Palindrome; Longest Substring Without Repeating Characters; Zigzag Conversion |
| Arrays, strings, and binary search | 11 | Palindrome Number; Remove Duplicates from Sorted Array; Remove Element; Find the Index of the First Occurrence in a String; Length of Last Word; Search Insert Position; Plus One; Merge Sorted Array; Longest Common Prefix; Best Time to Buy and Sell Stock; Valid Palindrome |
| Stack | 1 | Valid Parentheses |
| Linked lists | 5 | Merge Two Sorted Lists; Remove Duplicates from Sorted List; Linked List Cycle; Intersection of Two Linked Lists; Add Two Numbers |
| Binary trees | 8 | Same Tree; Symmetric Tree; Maximum Depth of Binary Tree; Convert Sorted Array to Binary Search Tree; Balanced Binary Tree; Minimum Depth of Binary Tree; Path Sum; Binary Tree Preorder Traversal |
| Dynamic programming / generated sequences | 3 | Climbing Stairs; Pascal's Triangle; Pascal's Triangle II |
| Hash counting / voting | 1 | Majority Element |
| Bit manipulation / arithmetic encoding | 6 | Add Binary; Single Number; Excel Sheet Column Title; Excel Sheet Column Number; Reverse Bits; Number of 1 Bits |
| **Total** | **37** | Each problem appears exactly once in the numbered record below |
| Bit manipulation / arithmetic encoding | 3 | Add Binary; Single Number; Excel Sheet Column Title |
| **Total** | **31** | Each problem appears exactly once in the numbered record below |

> The category counts use one primary category per problem. Several problems
> naturally overlap categories; for example, Plus One and Add Binary are both
> array/string traversal and arithmetic simulation.

## Detailed problem record

### 1. Palindrome Number

**Pattern:** Convert to a string and compare from both ends with two pointers.

**User's approach:** Convert the integer with `std::to_string`, initialize a
left and right index, and move inward while matching characters.

**Issues encountered:**

- The early special case returned `false` for a one-digit integer. A one-digit
  value is already a palindrome; more importantly, the normal loop handles it
  because `left < right` is initially false.
- The negative check was once written using the type name (`int`) rather than
  the variable name. Types cannot be compared as runtime values.
- A small primitive such as `int` was passed by `const&`, adding indirection
  without a useful copying benefit.
- Negative values need explicit interpretation: their string starts with `-`,
  so they are not palindromes under the problem definition.

**Corrected insight:** Prefer a base rule that lets the main invariant do the
work. After every successful comparison, the unexamined interval is
`[left, right]`; when the pointers meet or cross, all mirrored pairs matched.

**Complexity:** `O(d)` time and `O(d)` space for `d` decimal digits when using a
string.

### 2. Valid Parentheses

**Pattern / data structure:** LIFO matching with `std::stack<char>`.

**User's approach:** The first idea compared adjacent characters. It evolved
into pushing either opening brackets or their expected closing brackets.

**Issues encountered:**

- Adjacent matching cannot handle nesting such as `([])`.
- Calling `top()` or `pop()` before checking `empty()` is invalid.
- Matching each closer is insufficient unless the stack is also empty at the
  end; otherwise an unmatched opening remains.
- Condition order matters: `expected.empty() || expected.top() != ch` is safe
  because `||` short-circuits before `top()` when empty.

**Corrected insight:** A closer must match the most recently unmatched opener,
which is exactly a stack invariant. Pushing expected closers makes the check
especially direct.

**Complexity:** `O(n)` time and `O(n)` worst-case space.

### 3. Merge Two Sorted Lists

**Pattern / data structure:** Linked-list pointer splicing with a dummy node.

**User's approach:** Compare the current node values and choose the smaller
node for the result.

**Issues encountered:**

- Testing `list1->next` before proving `list1 != nullptr` can dereference null
  and also overlooks the final node.
- `current = list1` only reassigns a local pointer; it does not create a link.
  The list changes only through `current->next = list1`.
- After attaching a node, both the chosen input pointer and result tail must
  advance.
- The main loop should continue while **both** lists are non-null. Once either
  ends, the remaining suffix of the other list can be attached directly.
- The dummy is scaffolding, not result data. Return `dummy.next`, never the
  dummy itself or `&dummy`; a stack-local dummy does not survive the function.

**Corrected insight:** Maintain the invariant that `dummy.next ... current` is
the fully merged prefix and `current` is its tail.

**Complexity:** `O(n + m)` time and `O(1)` auxiliary space; existing nodes are
reused.

### 4. Remove Duplicates from Sorted Array

**Pattern:** Two pointers / read and write indices.

**User's approach:** An early attempt placed values in an `unordered_set`;
the corrected approach scans the sorted vector and writes each newly observed
value into the next output position.

**Issues encountered:**

- A set uses extra memory and does not express the in-place requirement.
- An unordered set does not preserve the sorted order.
- The underscores in examples are "don't care" positions, not characters to
  store in an integer vector.
- Passing the vector by value would modify a copy rather than the caller's
  vector.
- Empty input needs a correct initial write count.

**Corrected insight:** Sorting guarantees equal values are adjacent. Before
each read, indices `[0, uniqueIndex)` contain exactly one copy of every unique
value seen so far.

**Complexity:** `O(n)` time and `O(1)` extra space.

### 5. Remove Element

**Pattern:** Stable in-place filtering with a write index.

**User's approach:** The initial version shifted from `nums[i + 1]` after
finding the target. The corrected version copies only retained values.

**Issues encountered:**

- Reading `nums[i + 1]` on the last iteration is out of bounds.
- Repeated shifting is awkward for adjacent removals and can degrade to
  `O(n^2)`.
- The requested return value is the number **kept**, not the number removed.
- The write target receives the current retained number, not `val`.

**Corrected insight:** At all times, `[0, writeIndex)` contains exactly the
non-`val` elements already scanned.

**Complexity:** `O(n)` time and `O(1)` extra space.

### 6. Find the Index of the First Occurrence in a String (`strStr`)

**Pattern:** Enumerate candidate starts and compare a needle-length substring.

**User's approach:** Use `substr` at each possible starting index.

**Issues encountered:**

- A variable cannot be used as the source of its own initializer; call
  `haystack.substr(...)`, not a method on the string being declared.
- The compared substring length must be `needle.size()`, not one larger.
- Using `<` instead of `<=` misses the final legal starting index.
- With unsigned sizes, `haystack.size() - needle.size()` underflows if the
  needle is longer. Check that case first.
- An empty needle returns index `0`.

**Corrected insight:** Candidate `i` is valid exactly when
`i + needle.size() <= haystack.size()`. Guarding relative lengths before
subtracting makes the unsigned arithmetic safe.

**Complexity:** The simple substring version is `O(nm)` time in the worst case
and uses up to `O(m)` temporary space per copied substring.

### 7. Length of Last Word

**Pattern:** String parsing, either with a stream or a backward scan.

**User's approach:** Tokenize using `std::istringstream` and retain the latest
word.

**Issues encountered:**

- `words[words.size()]` is one past the last valid index.
- Storing every word is unnecessary when only the latest token matters.
- A direct reverse scan must first skip trailing spaces, then count until the
  preceding space or beginning.

**Corrected insight:** Container size is a count, not a valid final index.
`back()` expresses the intended last-element access more safely.

**Complexity:** `O(n)` time. The stream solution stores the current/last word;
a backward index scan uses `O(1)` auxiliary space.

### 8. Search Insert Position

**Pattern:** Lower-bound binary search over a half-open interval.

**User's approach:** Search a sorted vector for the target or the place it
belongs.

**Issues encountered:**

- `left + right / 2` applies division first and is not the midpoint of the
  current interval. Use `left + (right - left) / 2`.
- Looking at `middle - 1` or `middle + 1` creates boundary hazards and is not
  needed.
- Updating the wrong boundary can fail to shrink the interval.
- A half-open range `[left, right)` permits `right == nums.size()` and naturally
  represents insertion after the last element.

**Corrected insight:** Search for the first index whose value is at least the
target. Preserve that answer inside `[left, right)` until the interval is empty.

**Complexity:** `O(log n)` time and `O(1)` space.

### 9. Plus One

**Pattern:** Right-to-left digit-array carry propagation.

**User's approach:** The initial idea converted all digits to an integer; the
corrected solution updates decimal digits directly from the least significant
end.

**Issues encountered:**

- The represented number may have far more digits than any built-in integer,
  so conversion can overflow.
- Starting at `digits.size()` is one past the end.
- Writing `static_cast<int>(digits.size() - 1)` performs unsigned subtraction
  before the cast. The safer general form is
  `static_cast<int>(digits.size()) - 1`.
- Every trailing `9` becomes `0`; forgetting the all-9 case loses the new
  leading `1`.

**Corrected insight:** Stop as soon as a digit below `9` is incremented. If no
such digit exists, the result is one digit longer.

**Complexity:** `O(n)` worst-case time. `O(1)` extra space if modifying and
returning the input vector; `O(n)` in the repository version that copies it.

### 10. Add Binary

**Pattern:** Add two strings from right to left with one carry bit.

**User's approach:** Traverse the least significant characters, convert each
`'0'`/`'1'` to a numeric digit, append result bits, then reverse the collected
string.

**Issues encountered:**

- A loop that requires both indices to remain valid stops too early when the
  strings have unequal lengths. Continue while either side remains **or**
  `carry != 0`.
- Carry must be recomputed from each column's total:
  `bit = total % 2`, `carry = total / 2`. Allowing stale carry state to leak
  across iterations produces wrong bits.
- A final carry must be appended.
- Character arithmetic must use `a[i] - '0'`, not the character code itself.
- `std::reverse` modifies a range in place and returns `void`; it cannot be used
  as though it returns the reversed string.

**Corrected insight:** Treat absent digits as zero and use one uniform loop for
both unequal lengths and final carry.

**Complexity:** `O(max(n, m))` time and `O(max(n, m))` result space.

### 11. Climbing Stairs

**Pattern:** Fibonacci-style dynamic programming.

**User's approach:** Express the number of ways to reach step `n` as the ways
from `n - 1` plus the ways from `n - 2`, initially through recursion.

**Issues encountered:**

- Wrong base cases change the entire sequence. A useful definition is
  `ways(0) = 1` and `ways(1) = 1`, or equivalently special-case `n <= 2` under
  a different formulation.
- Recursive calls must use the decreasing parameters `n - 1` and `n - 2`;
  calling with the wrong variable can prevent progress.
- The function must return the computed recursive sum. Merely calling both
  branches discards their answers.
- Reusing a variable name inside a narrower scope can shadow the value intended
  for the return.
- Plain recursion repeats subproblems exponentially.

**Corrected insight:** Define precisely what `dp[i]` means, verify the first two
values, then iteratively keep only the previous two states.

**Complexity:** `O(n)` time and `O(1)` extra space iteratively; naive recursion
is `O(2^n)` time and `O(n)` call-stack space.

### 12. Remove Duplicates from Sorted List

**Pattern / data structure:** Single linked-list traversal.

**User's approach:** Compare each node with its successor and bypass duplicate
successors.

**Issues encountered:**

- A `ListNode*` is a pointer; access its fields with `->`. A `ListNode` object
  uses `.`. The node itself is not interchangeable with `node->val`.
- Check `current != nullptr` before reading `current->next`, and check the next
  pointer before reading its value.
- When deleting/bypassing a duplicate, keep `current` in place because another
  duplicate may follow. Advance only when the next value differs.
- Failing to advance in the non-duplicate branch causes an infinite loop.

**Corrected insight:** For a sorted list, all duplicates of a value are
contiguous. Repeatedly splice out `current->next` while its value equals
`current->val`.

**Complexity:** `O(n)` time and `O(1)` extra space.

### 13. Merge Sorted Array

**Pattern:** Three pointers filling from the back.

**User's approach:** Merge the meaningful prefix of `nums1` and all of `nums2`
without allocating a second output array.

**Issues encountered:**

- Filling from the front overwrites unread values in `nums1`.
- The meaningful final elements are at indices `m - 1`, `n - 1`, and
  `m + n - 1`; confusing counts with indices causes off-by-one errors.
- The loop only needs to guarantee that all `nums2` values are copied. Any
  leftover `nums1` prefix is already in its correct location.
- Pointer conditions must be checked before indexing.

**Corrected insight:** The unused capacity is at the back, so place the largest
remaining value there and move left.

**Complexity:** `O(m + n)` time and `O(1)` extra space.

### 14. Same Tree

**Pattern:** Lockstep recursion over two binary trees.

**User's approach:** Compare corresponding nodes and recursively compare left
and right subtrees.

**Issues encountered:**

- Dereferencing either node before null checks is unsafe.
- The base cases must distinguish: both null is `true`; exactly one null is
  `false`; unequal values is `false`.
- Recursive calls must pair corresponding children (`p->left` with `q->left`,
  and right with right).
- Both recursive boolean results must be returned and combined with `&&`.

**Corrected insight:** The recursive contract is: "these two subtree roots
represent identical structures and values."

**Complexity:** `O(n)` time for the visited nodes and `O(h)` recursion-stack
space.

### 15. Symmetric Tree

**Pattern:** Mirrored two-tree recursion.

**User's approach:** Compare the root's left and right subtrees as mirror
images.

**Issues encountered:**

- Symmetry is not the same as equality. The cross-pairs are
  `left->left` with `right->right` and `left->right` with `right->left`.
- Base cases again require both-null, one-null, and value-mismatch distinctions.
- Comparing only immediate child values misses deeper structural asymmetry.
- Incorrect parameters in recursive calls can accidentally compare each
  subtree to itself.

**Corrected insight:** Write a helper whose contract is explicitly
`isMirror(a, b)`, then make every recursive pair reflect that contract.

**Complexity:** `O(n)` time and `O(h)` recursion-stack space.

### 16. Maximum Depth of Binary Tree

**Pattern:** Postorder recursion.

**User's approach:** Compute the depth of each subtree and add one for the
current node.

**Issues encountered:**

- The null subtree depth is `0`.
- Forgetting `return` around the recursive expression discards the result.
- The recurrence uses `max(leftDepth, rightDepth)`, not a sum.
- Recursing on the original root instead of `root->left` / `root->right` never
  moves toward the base case.

**Corrected insight:** Define depth as the number of nodes on the longest path
from the current root to a leaf:
`1 + max(maxDepth(left), maxDepth(right))`.

**Complexity:** `O(n)` time and `O(h)` stack space.

### 17. Convert Sorted Array to Binary Search Tree

**Pattern:** Divide and conquer using the middle element.

**User's approach:** Select a midpoint as the root, recursively build the left
half and right half, and connect the returned subtrees.

**Issues encountered:**

- A wrong empty-range base case can recurse forever. With inclusive boundaries,
  stop when `left > right`.
- Child calls must exclude the chosen midpoint.
- The returned recursive roots must be assigned to `root->left` and
  `root->right`; invoking recursion without using its return loses the tree.
- Midpoint computation should use `left + (right - left) / 2`.

**Corrected insight:** Each recursive call owns one disjoint sorted interval.
Choosing its midpoint keeps subtree heights as balanced as possible.

**Complexity:** `O(n)` time and `O(log n)` recursion stack for the balanced
result, excluding the `O(n)` nodes created.

### 18. Balanced Binary Tree

**Pattern:** Bottom-up height computation with early failure.

**User's approach:** Compare left and right subtree heights at each node.

**Issues encountered:**

- Recomputing height independently at every node is logically correct but can
  become `O(n^2)` on a skewed tree.
- Balance must hold at every node, not only at the root.
- A helper can return a sentinel such as `-1` for "already unbalanced"; this
  avoids carrying separate height and status traversals.
- Null must return height `0`, and child failure must be propagated before
  computing the parent's height.

**Corrected insight:** Use one postorder traversal. Every subtree returns either
its valid height or an unbalanced sentinel.

**Complexity:** `O(n)` time and `O(h)` stack space with the bottom-up method.

### 19. Longest Common Prefix

**Pattern:** Vertical scanning or comparison of lexicographic extremes.

**User's approach:** Compare characters across strings; sorting was also
considered as a shortcut because only the first and last sorted strings need
comparison.

**Issues encountered:**

- Accessing character `i` requires proving `i < word.size()` first.
- Expressions based on `size() - 1` can underflow for an empty string.
- Sorting the input changes its order. That may be allowed for a local copy,
  but should not silently mutate caller data if the interface does not require
  it.
- A mismatch must stop at the current prefix length, not include the mismatched
  character.

**Corrected insight:** The direct invariant is that every string matches the
candidate prefix through index `i - 1`. Stop before any out-of-range access or
first mismatch.

**Complexity:** Vertical scanning is `O(S)` time, where `S` is the number of
characters inspected, and `O(1)` extra space besides the returned prefix.
Sorting costs `O(k log k)` string comparisons and may modify input.

### 20. Minimum Depth of Binary Tree

**Pattern:** Tree recursion with a one-child special case, or BFS.

**User's approach:** Adapt the maximum-depth recurrence by choosing the smaller
subtree depth.

**Issues encountered:**

- `1 + min(leftDepth, rightDepth)` is wrong when exactly one child is null:
  the zero from the absent side incorrectly wins.
- A leaf means **both** `left` and `right` are null.
- If one child is absent, minimum depth must follow the existing child.
- Null-root depth is `0`.

**Corrected insight:** Minimum depth is the shortest path to a real leaf, not to
an absent child pointer. BFS is also natural because the first dequeued leaf
has minimum depth.

**Complexity:** `O(n)` worst-case time. DFS uses `O(h)` stack space; BFS uses up
to `O(w)` queue space.

### 21. Path Sum

**Pattern:** Root-to-leaf DFS with a decreasing remainder.

**User's approach:** Subtract each visited node value from the target and
recurse into children.

**Issues encountered:**

- The question is not whether all values in the tree add to the target; it asks
  for one continuous root-to-leaf path.
- A match at an internal node is insufficient. The endpoint must be a leaf,
  defined by both child pointers being null.
- Each branch receives its own remaining sum; accidental shared mutation can
  contaminate sibling branches.
- Recursive boolean results must be returned with `||`.

**Corrected insight:** At a leaf, succeed exactly when
`remaining == leaf->val`; otherwise recurse with
`remaining - root->val`.

**Complexity:** `O(n)` time and `O(h)` stack space.

### 22. Pascal's Triangle

**Pattern:** Dynamic row construction.

**User's approach:** Build one row at a time from the preceding row.

**Issues encountered:**

- Every row begins and ends with `1`.
- Interior entry `row[j]` comes from
  `previous[j - 1] + previous[j]`.
- Loop boundaries must avoid reading outside the previous row.
- Allocating the current row with its final size before filling reduces special
  cases.

**Corrected insight:** Row `i` has `i + 1` elements; only indices `1` through
`i - 1` need the recurrence.

**Complexity:** `O(numRows^2)` time and `O(numRows^2)` output space.

### 23. Pascal's Triangle II

**Pattern:** One-row in-place dynamic programming.

**User's approach:** Reuse a single vector rather than storing the full
triangle.

**Issues encountered:**

- Updating left-to-right overwrites `row[j - 1]` before it is used for the same
  generation.
- Updates must run from right to left so every read still sees the previous
  row.
- The row needs enough size, or a trailing `1` must be appended before interior
  updates.

**Corrected insight:** Direction is part of an in-place DP algorithm. Traverse
opposite the dependency direction to preserve old values.

**Complexity:** `O(rowIndex^2)` time and `O(rowIndex)` output/working space.

### 24. Best Time to Buy and Sell Stock

**Pattern:** One pass with a running minimum.

**User's approach:** The early brute-force method considered every earlier buy
and later sell pair.

**Issues encountered:**

- The nested-loop solution can be logically correct while taking `O(n^2)`.
- The buy must occur before the sell; sorting prices would destroy the time
  ordering and is therefore invalid.
- Profit should stay at least zero when no profitable transaction exists.

**Corrected insight:** On each day, the only past fact needed is the lowest
price seen so far. Compare today's price against it, then update the running
minimum.

**Complexity:** `O(n)` time and `O(1)` space for the optimized method.

### 25. Valid Palindrome

**Pattern:** Filter/normalize with two pointers.

**User's approach:** Ignore non-alphanumeric characters, compare
case-insensitively, and move from both ends.

**Issues encountered:**

- `isalpha` accepts letters only; the problem requires alphanumeric characters,
  so use `isalnum`.
- Character classification and case conversion should receive an
  `unsigned char` value to avoid undefined behavior for negative plain `char`
  values.
- Pointer skip conditions must check bounds before indexing.
- Building a cleaned reverse is valid but uses extra space.
- `std::reverse` mutates a range and returns `void`; it does not produce a new
  string expression.

**Corrected insight:** Skip invalid characters independently on both sides,
then compare normalized valid characters only when both indices remain valid.

**Complexity:** `O(n)` time and `O(1)` extra space with direct two pointers.

### 26. Single Number

**Pattern:** XOR cancellation.

**User's approach:** Sorting and set-based counting were natural first
solutions; the final target is a constant-space linear pass.

**Issues encountered:**

- A set or hash map uses `O(n)` extra space.
- Sorting uses at least `O(n log n)` time and may modify input.
- Those methods can find the right answer but miss the explicit linear-time,
  constant-extra-space requirement.

**Corrected insight:** XOR is associative and commutative,
`x ^ x == 0`, and `x ^ 0 == x`; all paired values cancel, leaving the unique
one.

**Complexity:** `O(n)` time and `O(1)` space.

### 27. Linked List Cycle

**Pattern:** Floyd's tortoise-and-hare pointers.

**User's approach:** Move one pointer one step and another two steps, then test
whether they meet.

**Issues encountered:**

- Before moving the fast pointer twice, prove both `fast` and `fast->next` are
  non-null.
- Comparing both pointers at the initial head before either moves creates an
  immediate false positive.
- Move first, then compare.
- A visited-node set works but uses `O(n)` memory; Floyd's method satisfies the
  constant-space goal.

**Corrected insight:** In an acyclic list, the fast pointer reaches null. In a
cycle, relative motion guarantees that the two pointers eventually meet.

**Complexity:** `O(n)` time and `O(1)` space.

### 28. Binary Tree Preorder Traversal

**Pattern:** Root-left-right DFS, recursive or iterative with a stack.

**User's approach:** Visit the current node before traversing its children.

**Issues encountered:**

- Preorder's sequence is **root, left, right**; it can be confused with inorder
  or postorder.
- The null base case must return without appending.
- Recursive calls should share the same result vector by reference.
- In an iterative version, push the right child before the left because a stack
  pops the left child first.
- Forgetting to use the returned or shared result loses recursive work.

**Corrected insight:** State the visit order before coding. Traversal names are
defined by where the root visit occurs relative to the two subtree visits.

**Complexity:** `O(n)` time and `O(h)` recursive stack space; iterative stack
space is `O(h)` on a balanced tree and up to `O(n)`.

### 29. Intersection of Two Linked Lists

**Pattern:** Pointer switching to equalize path lengths.

**User's approach:** Compare nodes while traversing the two lists; the robust
method redirects each pointer to the other list's head at its own end.

**Issues encountered:**

- Intersection means the exact same node address, not merely equal node values.
- Comparing `a->val == b->val` can report a false intersection.
- Length alignment can work, but pointer switching achieves the same effect
  without explicit length arithmetic.
- Rewiring the lists to mark or join them modifies input structure and risks
  creating cycles; it is unnecessary.
- Null transitions need to be handled without dereferencing null.

**Corrected insight:** After traversing `A + B` and `B + A`, both pointers have
covered equal total distance and meet at the shared node or both become null.

**Complexity:** `O(n + m)` time and `O(1)` space.

### 30. Excel Sheet Column Title

**Pattern:** Bijective (1-indexed) base-26 conversion.

**User's approach:** Repeatedly extract a letter from the right and reverse the
result.

**Issues encountered:**

- Excel has no zero digit: `A = 1`, ..., `Z = 26`, `AA = 27`.
- Ordinary `n % 26` maps multiples of 26 to zero rather than `Z`.
- Decrementing first (`--columnNumber`) converts each step into zero-based
  remainder arithmetic.
- Generated letters arrive in reverse order.
- Again, `std::reverse` changes the string in place and returns `void`.

**Corrected insight:** Each iteration uses
`remainder = (n - 1) % 26` and `n = (n - 1) / 26`.

**Complexity:** `O(log_26 n)` time and `O(log_26 n)` result space.

### 31. Add Two Numbers

**Pattern / data structure:** Parallel linked-list traversal with carry and a
dummy result head.

**User's approach:** Add corresponding node digits, append a result node for
the ones digit, and carry the tens digit forward.

**Issues encountered:**

- A loop conditioned on both lists being non-null drops the remaining digits
  of the longer list. Continue while either list remains or carry is nonzero.
- Missing nodes contribute zero.
- Carry must be recalculated every iteration using `sum / 10`; leaving an old
  carry set after a small sum corrupts later digits.
- A final carry needs its own result node.
- The result tail must advance after every appended node.
- The dummy node is not part of the number. Return `dummy.next`, not the dummy.
- If nodes are dynamically allocated, ownership must be clear: the result nodes
  outlive the local dummy, while returning a pointer to a stack-local dummy
  would dangle.
- Node pointers and node values must not be confused when adding.

**Corrected insight:** Use one uniform loop:
`while (l1 != nullptr || l2 != nullptr || carry != 0)`. Compute missing digits
as zero, create exactly one output node, update carry, and advance all available
pointers.

**Complexity:** `O(max(n, m))` time and `O(max(n, m))` space for the newly
created result list.

### 32. Longest Substring Without Repeating Characters

**Problem / level:** LeetCode 3 — Medium.

**Main technique / data structure:** Sliding window with
`std::unordered_set<char>`.

**User's approach:** Correctly recognized that a set could track characters and
that two indices could describe a moving substring.

**Issues encountered:**

- The loop used `a_set.size()` instead of `s.size()`, so its bound changed with
  the window rather than covering the input.
- An accidental semicolon after `for` detached the intended loop body.
- The membership call was written as `contain`; in C++20 the method is
  `contains` (or `find`/`count` in earlier standards).
- The duplicate condition was initially reversed.
- `rightIndex` could move out of bounds before indexing `s[rightIndex]`.
- On a duplicate, the code erased `s[rightIndex]`; the window must instead
  shrink from the left by erasing `s[left]`.
- `std::max(maxLength: ...)` used invalid named-argument-like syntax.

**Corrected insight / algorithm:** Maintain a window `[left, right]` whose set
contains no duplicates. For each `right`, repeatedly erase `s[left]` and
increment `left` while `s[right]` is already present. Insert `s[right]`, then
update the best length with `right - left + 1`.

**Complexity:** `O(n)` time because each character enters and leaves the set at
most once, and `O(min(n, alphabet size))` space.

**Learning takeaway:** A sliding window works when its invariant is explicit:
the set represents exactly the current duplicate-free window, and its length
comes from the indices, not from using the container as the input bound.

### 33. Zigzag Conversion

**Problem / level:** LeetCode 6 — Medium.

**Main technique / data structure:** Direction-changing simulation with one
`std::string` per row in a `std::vector<std::string>`.

**User's approach:** First tried to model the layout with two-dimensional
`x`/`y` coordinates, then allocated a vector of rows.

**Issues encountered:**

- The row vector was initially not allocated.
- After allocating rows, each inner string was still empty, so
  `output[y][x]` remained out of bounds.
- The bottom check used `y < numRows`, which still permits `y == numRows`
  after an increment.
- Brace and `else` placement caused control-flow and syntax problems.
- `x` was unused once the representation became row-based.
- Filtering spaces was unnecessary and would change valid input.
- The first complete draft omitted its return statement.
- The `numRows == 1` edge case was missed.
- A range loop shadowed an existing variable name.

**Corrected insight / algorithm:** If `numRows == 1`, return `s`. Otherwise,
allocate `numRows` strings, append each character with `push_back` to the
current row, and reverse direction whenever the current row is `0` or
`numRows - 1`. Concatenate the rows at the end.

**Complexity:** `O(n)` time and `O(n)` space for the row strings and result.

**Learning takeaway:** Choose a representation that stores only the required
output. Allocating a container of strings creates the rows, but indexing inside
an empty string is not the same as appending to it.

### 34. Majority Element

**Problem / level:** LeetCode 169 — Easy.

**Main technique / data structure:** Frequency counting with
`std::unordered_map<int, int>`, followed by Boyer-Moore voting for constant
space.

**User's approach:** The first version compared every value only with
`nums[0]`. A map-based revision then counted occurrences, before the work moved
to Boyer-Moore voting.

**Issues encountered:**

- An `unordered_map` was declared but not used in the first approach.
- `max_count` was read without initialization, and the function omitted a
  return.
- `dic[i] = dic[i]++` assigns the old post-increment value back, cancelling the
  increment.
- The map revision returned the frequency instead of the element and missed a
  semicolon.
- In Boyer-Moore, `candidate = 0` and then `count = 0` were used inside
  conditions instead of equality comparisons with `==`.
- Resetting `candidate` to zero was unnecessary and obscured the invariant.

**Corrected insight / algorithm:** With a map, increment `counts[value]` and
return the value whose count exceeds `nums.size() / 2`. For Boyer-Moore, when
`count == 0`, choose the current value as the candidate; add one for the same
value and subtract one for a different value. The guaranteed majority survives
pairwise cancellation.

**Complexity:** The map solution is `O(n)` time and `O(n)` space. Boyer-Moore is
`O(n)` time and `O(1)` space.

**Learning takeaway:** Assignment changes state; equality tests state. The
Boyer-Moore invariant is simpler when candidate selection happens only at
`count == 0`, followed by one uniform `+1`/`-1` update.

### 35. Excel Sheet Column Number

**Problem / level:** LeetCode 171 — Easy.

**Main technique / data structure:** Left-to-right positional accumulation in
bijective base 26; no auxiliary container is needed.

**User's approach:** Correctly converted each letter with
`columnTitle[i] - 'A' + 1`, but was unsure how to combine the positional values.

**Issues encountered:**

- The accumulation expression was incomplete and contained an invalid `44`
  artifact.
- The function had no return statement.
- The place-value relationship between successive letters was not yet clear.

**Corrected insight / algorithm:** Read letters from left to right and apply
`total = total * 26 + value`. Multiplication shifts the accumulated prefix one
base-26 position before the next 1-to-26 digit is added.

**Complexity:** `O(n)` time and `O(1)` space.

**Learning takeaway:** This is the inverse of Excel Sheet Column Title.
Encoding repeatedly extracts rightmost digits; decoding repeatedly shifts the
current prefix and adds the next digit.

### 36. Reverse Bits

**Problem / level:** LeetCode 190 — Easy.

**Main technique / data structure:** Fixed-width bit extraction, shifting, and
bitwise OR with `uint32_t`.

**User's approach:** There was no initial algorithm; the study introduced
`n & 1`, shifts, and bitwise OR. The first implementation collected one bit per
iteration.

**Issues encountered:**

- The result variable was not initialized, so shifting it read an indeterminate
  value.
- Semicolons were missing.
- A signed integer type was used even though the problem operates on 32-bit
  unsigned data.
- Inserting the low bit before shifting the result shifted every collected bit,
  including the final one, one position too far.

**Corrected insight / algorithm:** Initialize `uint32_t result = 0` and repeat
exactly 32 times:
`result = (result << 1) | (n & 1); n >>= 1;`. Shift the accumulated result
first, insert the extracted bit, then advance the input.

**Complexity:** `O(1)` time for exactly 32 iterations and `O(1)` space.

**Learning takeaway:** For stateful bit algorithms, operation order is part of
correctness. Write the before-and-after bit positions for one iteration before
coding the loop.

### 37. Number of 1 Bits

**Problem / level:** LeetCode 191 — Easy.

**Main technique / data structure:** Bit testing and shifting; Brian
Kernighan's bit-clearing method is an optimized alternative.

**User's approach:** Reused the new bit concepts, but introduced a separate
`input` variable and a constructed `current`/digit mask.

**Issues encountered:**

- The condition checked `n & 1` while shifting `input`, so the same original
  bit of `n` was inspected repeatedly.
- The loop condition `current < input` did not represent when all bits had been
  processed.
- Building a separate `current` mask was unrelated to the simpler termination
  condition and made variable consistency harder.

**Corrected insight / algorithm:** The direct method repeatedly adds `n & 1` to
the count and shifts `n >>= 1`. Alternatively, Brian Kernighan's
`n &= n - 1` clears the lowest set bit each iteration, so increment the count
until `n == 0`.

**Complexity:** The direct fixed-width method is `O(1)` for 32 bits; Brian
Kernighan takes `O(k)` iterations for `k` set bits. Both use `O(1)` space.

**Learning takeaway:** Test and advance the same state variable. A loop's
condition should directly express remaining work; for bit counting, that is
either a fixed 32 iterations or `n != 0`.

## Recurring error taxonomy

| Error family | Representative examples | Why it happens | Review habit |
|---|---|---|---|
| Bounds and off-by-one | `words[words.size()]`; starting Plus One at `size()`; allowing Zigzag row `numRows`; advancing sliding-window `right` past the string | Confusing element count with last index | Write the valid interval beside every loop |
| Bounds and off-by-one | `words[words.size()]`; starting Plus One at `size()`; missing final `strStr` candidate | Confusing element count with last index | Write the valid interval beside every loop |
| Unsigned underflow | `size() - 1`; `haystack.size() - needle.size()` | `size()` returns an unsigned type | Guard emptiness/relative size first, or cast before subtracting |
| Unsafe condition order | `stack.top()` before `empty()`; `fast->next` before `fast` | Dereference occurs before safety is established | Put the cheapest safety guard on the left of `&&`/`||` |
| Object/pointer/value confusion | `current = list1` instead of linking; comparing list values for intersection | Several related entities have similar names | Say aloud: object, address, link, or stored value |
| Pointer progress failures | Not advancing result tail; advancing on duplicate removal; no progress in recursion | Every branch does not preserve a progress measure | Identify the exact variable that must move toward termination |
| Dummy-node mistakes | Returning dummy instead of `dummy.next`; unclear lifetime/ownership | Sentinel and real data are conflated | Draw sentinel separately and mark the returned first real node |
| Recursive contract errors | Wrong child parameters; missing returned result; wrong base case | Coding begins before defining the function's meaning | Write one sentence: "This function returns..." |
| Tree-path semantics | Whole-tree sum vs root-to-leaf Path Sum; incorrect leaf definition; min-depth null child | Visual tree terms are interpreted loosely | Define path and leaf before writing recurrence |
| Assignment versus equality | `candidate = 0` or `count = 0` inside a condition | `=` mutates and evaluates to the assigned value; it does not compare | Read conditions aloud and use `==` when asking a question |
| Initialization | Uninitialized `max_count` or reversed-bit result | A value is read before it has a defined starting state | Initialize every accumulator at declaration |
| State leakage/shadowing / inconsistency | Stale carry; range-loop shadowing; testing `n` while shifting `input` | State is updated in multiple places or similar names drift apart | Compute next state once and test/advance the same variable |
| Container versus element allocation | Allocated Zigzag rows but indexed empty row strings | Creating outer elements does not create indexed contents inside each string | Use `push_back` for growth; index only existing elements |
| Operation ordering | Inserted a bit before shifting the reversed result; erased the duplicate instead of the window's left edge | Individually valid operations break the invariant in the wrong order | Trace one iteration as ordered state transitions |
| State leakage/shadowing | Stale carry; local variable shadows result | State is updated in multiple places | Compute next state once per iteration with distinct names |
| Requirement mismatch | Set for in-place deduplication; sort/set for Single Number | First correct-output idea ignores constraints | Translate every constraint into a design test |
| Directional in-place update | Pascal II updated left-to-right | New values overwrite dependencies | Determine whether dependencies are old-left or old-right |
| Complexity gap | `O(n^2)` stock-pair search | Brute force models the statement directly | Ask what one summary of the prefix would replace an inner loop |
| Library/API misconception | Treating `std::reverse` as returning a string | Mutation APIs and value-returning APIs are confused | Check whether the function mutates, returns, or both |
| Character classification | `isalpha` instead of `isalnum` | Similar API names hide semantic differences | Restate the exact accepted character set |
| Edge cases | Missing `numRows == 1`; empty inputs; final carry; null children | The main path is coded before boundary behavior is named | List smallest, empty, and boundary inputs before coding |
| Syntax and punctuation | Typos, missing semicolons/returns, stray semicolon after `for`, brace/`else` mismatch | C++ syntax load distracts from algorithm logic | Compile after the smallest complete unit and read the first error |
| Syntax and naming | Typos, missing semicolons, type name used as a variable | C++ syntax load distracts from algorithm logic | Compile after the smallest complete unit and read the first error |

### Concrete safety patterns

Short-circuit guards should make the unsafe expression unreachable:

```cpp
if (stack.empty() || stack.top() != ch) {
    return false;
}

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
}
```

For recursive tree work, write base cases before reading node fields:

```cpp
if (root == nullptr) return 0;
return 1 + std::max(depth(root->left), depth(root->right));
```

These are not merely style preferences. Their left-to-right order is part of
memory safety and termination.

## Data structures and algorithms learned

| Topic | What was learned | Problems that exercised it |
|---|---|---|
| `std::vector` | Indexing, references, in-place writes, outer allocation versus inner element contents | Remove Duplicates, Remove Element, Merge Sorted Array, Pascal I/II, Plus One, Zigzag Conversion |
| `std::string` | Indexing, `substr`, `push_back`, character arithmetic, normalization, reverse-in-place | Palindrome Number, `strStr`, Add Binary, Valid Palindrome, Excel columns, Zigzag Conversion |
| `std::stack` | LIFO matching and safe `top()` / `pop()` access | Valid Parentheses, iterative preorder |
| `std::queue` | FIFO model and level-order/BFS reasoning | Minimum Depth alternative and tree level-order study |
| `std::unordered_set` | Fast membership, no indexing/order, extra-space tradeoff, sliding-window membership | Early deduplication, cycle/single-number alternatives, Longest Substring |
| `std::unordered_map` | Key-value lookup, frequency counting, and increment semantics | General character-counting study and Majority Element |
| `std::vector` | Indexing, references, in-place writes, capacity already reserved by a problem | Remove Duplicates, Remove Element, Merge Sorted Array, Pascal I/II, Plus One |
| `std::string` | Indexing, `substr`, character arithmetic, normalization, reverse-in-place | Palindrome Number, `strStr`, Add Binary, Valid Palindrome, Excel Column Title |
| `std::stack` | LIFO matching and safe `top()` / `pop()` access | Valid Parentheses, iterative preorder |
| `std::queue` | FIFO model and level-order/BFS reasoning | Minimum Depth alternative and tree level-order study |
| `std::unordered_set` | Fast membership, no indexing/order, extra-space tradeoff | Early deduplication and cycle/single-number alternatives |
| `std::unordered_map` | Key-value lookup and frequency counting | General character-counting study and matching alternatives |
| `std::priority_queue` | Heap interface and max-heap default | General topic; not counted as a distinct solved problem |
| Linked lists | `ListNode*`, `->`, traversal, splicing, identity, dummy heads | Merge Lists, Deduplicate List, Cycle, Intersection, Add Two Numbers |
| Binary trees | Null/leaf semantics, subtree contracts, DFS orders, height/depth | Same Tree through Binary Tree Preorder Traversal |
| Two pointers | Inward comparison, read/write filtering, parallel traversal | Palindromes, array filtering, linked-list intersection |
| Binary search | Half-open intervals and lower-bound invariant | Search Insert Position |
| Recursion | Base cases, progress, return propagation, mirrored parameters | Tree problems and initial Climbing Stairs |
| Dynamic programming | Reusing previous states and preserving dependencies | Climbing Stairs, Pascal's Triangle II |
| Sliding window | Maintaining a valid interval while left and right pointers move | Longest Substring Without Repeating Characters |
| Boyer-Moore voting | Majority cancellation with a candidate and count invariant | Majority Element |
| Bit manipulation | XOR cancellation, low-bit testing, shifts, OR, and clearing the lowest set bit | Single Number, Reverse Bits, Number of 1 Bits |
| Arithmetic simulation | Carry propagation and 1-indexed base conversion in both directions | Plus One, Add Binary, both Excel column problems, Add Two Numbers |
| Bit manipulation | XOR cancellation | Single Number |
| Arithmetic simulation | Carry propagation and 1-indexed base conversion | Plus One, Add Binary, Excel title, Add Two Numbers |
| Complexity analysis | Correctness versus constraint compliance | Stock, Single Number, Balanced Tree, in-place problems |

## Progression and strengths

1. **Pattern recognition improved.** The work progressed from example-specific
   manipulation to named patterns: stack matching, write index, lower bound,
   dummy node, DFS contract, running minimum, and Floyd pointers.
2. **Constraint awareness improved.** The user learned to distinguish "returns
   the correct value" from "meets in-place, constant-space, or target-time
   requirements."
3. **Edge-case reasoning became more concrete.** Empty inputs, one-element
   inputs, all-9 digits, unequal-length operands, null children, one-child
   trees, and final carry became explicit design cases.
4. **Pointer understanding broadened.** Work now covers linking versus local
   reassignment, identity versus equal value, safe advancement, dummy nodes,
   and cycle detection.
5. **Recursion moved toward contracts.** Tree problems exposed a reusable
   method: define the subtree answer, establish null/leaf cases, recurse on
   smaller subtrees, and return the combined result.
6. **Good instinct for simple first solutions.** String conversion, brute-force
   pairs, sets, sorting, and streams are often reasonable correctness-first
   approaches. The next skill is evaluating them systematically against every
   stated constraint.
7. **Medium-level iteration is underway.** Longest Substring introduced a true
   sliding-window invariant, while Zigzag Conversion showed how choosing one
   output string per row can replace fragile two-dimensional coordinates.
8. **Counting and compact state both improved.** Majority Element connected
   hash-map frequency counting to Boyer-Moore's `O(1)`-space cancellation
   invariant.
9. **Numeric representations now work in both directions.** The two Excel
   column problems connect repeated digit extraction with left-to-right
   positional accumulation.
10. **Foundational bit operations are established.** Low-bit testing, shifts,
    OR, fixed-width iteration, and `n &= n - 1` now form a reusable base for
    later bit problems.

## Recommended next learning plan

### Phase 1: Correctness mechanics (1 week)

- Re-solve six representative problems without notes: Search Insert Position,
  Merge Two Sorted Lists, Minimum Depth, Longest Substring, Zigzag Conversion,
  and Reverse Bits.
- Re-solve five representative problems without notes: Remove Element, Search
  Insert Position, Merge Two Sorted Lists, Minimum Depth, and Add Two Numbers.
- Before coding each one, write:
  - valid index/pointer range;
  - loop or recursive invariant;
  - termination/progress measure;
  - expected time and space.
- Compile after each complete function and classify each compiler error rather
  than patching it blindly.

### Phase 2: Tree recursion fluency (1 week)

- Implement preorder, inorder, postorder, and level order from memory.
- Re-solve Same Tree, Symmetric Tree, Maximum Depth, Minimum Depth, Path Sum,
  and Balanced Binary Tree.
- For every helper, write its contract in one sentence and test null, leaf,
  one-child, balanced, and skewed trees.
- Compare DFS and BFS for Minimum Depth to understand when search order gives an
  early answer.

### Phase 3: Linked-list pointer fluency (1 week)

- Draw each pointer before changing any `next` link.
- Re-solve Merge Two Sorted Lists, Remove Duplicates from Sorted List,
  Linked List Cycle, Intersection, and Add Two Numbers.
- Trace lists of lengths 0, 1, unequal lengths, repeated values, shared suffixes,
  and final carry.
- Explicitly label node address, node value, and next link on paper.

### Phase 4: Constraint-driven optimization (1 week)

- Solve each problem first for correctness, then inspect constraints.
- Practice converting:
  - nested loops into a running prefix summary (Stock);
  - set/sort solutions into algebraic constant-space logic (Single Number);
  - full-table DP into rolling state (Climbing Stairs, Pascal II);
  - extra output buffers into safe backward in-place writes (Merge Sorted
    Array);
  - hash counting into Boyer-Moore voting (Majority Element);
  - 32-step bit scans into set-bit-only iteration (Number of 1 Bits).
- Record both versions and explain precisely what resource changed.

### Phase 5: Hashing, bases, and bits consolidation

- Re-solve Longest Substring and Majority Element, stating each invariant before
  coding.
- Implement both Excel column conversions back-to-back and explain why one uses
  decrement-before-remainder while the other uses multiply-then-add.
- Trace Reverse Bits with a small-width example and implement Number of 1 Bits
  with both shifting and Brian Kernighan's method.
- For every loop, verify initialization, condition, state update, and operation
  order before compiling.

### Phase 6: Expansion
    Array).
- Record both versions and explain precisely what resource changed.

### Phase 5: Consolidation and expansion

- Add hash-map problems such as Two Sum and Valid Anagram.
- Add queue/BFS problems such as Binary Tree Level Order Traversal.
- Add two-pointer problems such as Move Zeroes.
- Add one basic heap problem after `priority_queue` operations are comfortable,
  then try one additional sliding-window problem.
- Add one basic heap problem after `priority_queue` operations are comfortable.
- Use spaced repetition: revisit a problem after 1 day, 1 week, and 1 month,
  coding from the invariant rather than memorizing lines.

## Reusable future-solution checklist

1. **Restate the contract:** What exactly is returned or modified?
2. **Extract constraints:** In place? Stable order? Constant space? Required
   complexity?
3. **Name the pattern:** Two pointers, stack, binary search, DFS/BFS, DP, hash,
   XOR, or arithmetic simulation?
4. **Define safety:** What indices/pointers may be accessed, and in what
   short-circuit order?
5. **Define progress:** Which index, pointer, interval, or recursive parameter
   moves toward termination on every path?
6. **Write edge cases:** Empty, one item, all equal/all 9, unequal lengths,
   null, leaf, one child, no valid answer.
7. **Protect old data:** For in-place work, should traversal go forward or
   backward?
8. **Check state:** Is carry/temporary state recomputed, reset, returned, and
   propagated exactly once?
9. **Check identity:** Does the problem compare values or actual node identity?
10. **Trace one tiny case:** Record every index, pointer, stack entry, or
    recursive return.
11. **Analyze complexity:** Include auxiliary space and recursion stack; compare
    against requirements.
12. **Compile and test deliberately:** Fix the first compiler error first, then
    test boundaries before typical examples.

## Related repository records

- [Earlier discussion log](../notes/discussion-log.md)
- [Earlier session summary](../notes/session-summary.md)
- [Error tracker](../trackers/error-log.md)
- [Data-structures tracker](../trackers/data-structures.md)
- [Dedicated early problem notes](../problems/)
- [Runnable early C++ examples](../src/)
