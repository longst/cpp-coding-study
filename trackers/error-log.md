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

