# Error Log

Use this file to track recurring C++ mistakes, why they happen, and the correct pattern.

| Date | Topic | Mistake | Why it fails | Correct pattern |
|---|---|---|---|---|
| 2026-09-05 | Palindrome number | Returned `false` for one-digit numbers | One-digit numbers are palindromes | Let the two-pointer loop handle length 1, or return `true` |
| 2026-09-05 | Palindrome number | Wrote `if (int < 0)` | `int` is a type, not the variable name | Use `if (input < 0)` |
| 2026-09-05 | Valid parentheses | Tried matching only adjacent characters | Valid brackets may be nested, not adjacent | Use `std::stack<char>` |
| 2026-09-06 | Merge two sorted lists | Used `list1->next` in loop condition | Crashes if `list1 == nullptr`; also skips last node | Use `while (list1 != nullptr && list2 != nullptr)` |
| 2026-09-06 | Merge two sorted lists | Wrote `currentNode = list1` | Reassigns local pointer but does not connect the list | Use `currentNode->next = list1` |
| 2026-09-06 | Merge two sorted lists | Returned dummy node itself | Dummy is only an auxiliary node | Return `dummy.next` |
| 2026-09-06 | Remove duplicates | Used `unordered_set` | It does not preserve sorted order and is not in-place | Use two pointers/write index |
| 2026-09-06 | Remove element | Used `nums[i] = nums[i + 1]` | Last iteration reads out of bounds and does not solve repeated removals | Use a write index for values not equal to `val` |
| 2026-09-06 | Remove element | Returned removed count | Problem asks for kept count `k` | Return `writeIndex` |
| 2026-09-06 | String search | Called `sub_string.substr(...)` while declaring `sub_string` | Source string should be `haystack` | Use `haystack.substr(i, needle.size())` |
| 2026-09-06 | String search | Used `needle.size() + 1` | Substring length should equal needle length | Use `needle.size()` |
| 2026-09-06 | String search | Loop used `<` instead of `<=` | Misses the last valid starting index | Use `i <= haystack.size() - needle.size()` |
| 2026-09-06 | Last word length | Used `words[words.size()]` | Vector indices end at `size() - 1` | Use `words.back()` or `words[words.size() - 1]` |
| 2026-09-06 | Search insert position | Used `middle = min + max / 2` | Incorrect midpoint when left boundary is not zero | Use `left + (right - left) / 2` |
| 2026-09-06 | Search insert position | Accessed `middle + 1` and `middle - 1` | Can go out of bounds | Use standard binary search boundaries |
| 2026-09-06 | Plus one | Converted digit vector to integer | Large input can overflow integer types | Process digits from right to left with carry |
| 2026-09-07 | Plus one | Started loop at `digits.size()` | Valid last index is `digits.size() - 1` | Start at `static_cast<int>(digits.size()) - 1` |
| 2026-09-18 | Longest substring | Used the window set's size as the input loop bound and erased the right character on duplicates | The set changes size and the window must shrink from its left edge | Bound `right` by `s.size()` and erase `s[left++]` until the duplicate is gone |
| 2026-09-18 | Zigzag conversion | Allocated row strings but indexed characters inside still-empty strings | Allocating the outer vector does not allocate indexed characters in each string | Append with `rows[currentRow].push_back(ch)` and toggle direction at row bounds |
| 2026-09-18 | Majority element | Used `=` instead of `==` in Boyer-Moore conditions and wrote `dic[i] = dic[i]++` | Assignment mutates state, and post-increment returns the old value that was assigned back | Compare with `==`; count with `++dic[value]` |
| 2026-09-18 | Excel column number | Converted each character correctly but did not accumulate its position | Each new digit must shift the previous prefix by one base-26 place | Use `total = total * 26 + (ch - 'A' + 1)` |
| 2026-09-18 | Reverse bits | Inserted a bit before shifting an uninitialized result | The final inserted bit was shifted once too far, and uninitialized reads are invalid | Start with `uint32_t result = 0`, then use `result = (result << 1) \| (n & 1)` |
| 2026-09-18 | Number of 1 bits | Tested `n & 1` while shifting a different variable | The same original bit was inspected repeatedly | Test and shift the same variable, or clear bits with `n &= n - 1` |
