# Comprehensive Session Log & Discussion Record

**Date:** September 5–7, 2026  
**Topic:** C++ Fundamentals, Data Structures, STL Containers, and LeetCode-style Practice  
**Repository:** `/Users/shilong/sdev/study/cpp-coding-study`

---

## Table of Contents

1. [Learning Roadmap & Strategy](#1-learning-roadmap--strategy)
2. [STL Containers Overview](#2-stl-containers-overview)
3. [Problem 1: Palindrome Number](#3-problem-1-palindrome-number)
4. [Problem 2: Valid Parentheses & `std::stack`](#4-problem-2-valid-parentheses--stdstack)
5. [Problem 3: Merge Two Sorted Lists](#5-problem-3-merge-two-sorted-lists)
6. [Problem 4: Remove Duplicates from Sorted Array](#6-problem-4-remove-duplicates-from-sorted-array)
7. [Problem 5: Remove Element](#7-problem-5-remove-element)
8. [Problem 6: Find Index of First Occurrence (`strStr`)](#8-problem-6-find-index-of-first-occurrence-strstr)
9. [Problem 7: Search Insert Position](#9-problem-7-search-insert-position)
10. [Problem 8: Length of Last Word](#10-problem-8-length-of-last-word)
11. [Problem 9: Plus One & Integer Conversion](#11-problem-9-plus-one--integer-conversion)

---

## 1. Learning Roadmap & Strategy

### Question
> "How should I start learning basic C++ data structures?"

### Guidance
A structured 4-step approach:
1. **C++ Core Basics:** Pointers, references, structs/classes, memory, recursion, templates, STL basics (`vector`, `string`, `pair`).
2. **Sequential Data Structure Study:**
   - Arrays & Strings
   - Linked Lists (singly, doubly, circular)
   - Stacks & Queues
   - Trees (Binary trees, BST, Heaps)
   - Hash Tables (`unordered_map`, `unordered_set`)
   - Graphs (BFS, DFS)
   - Sorting & Searching
3. **Complexity Analysis:** Learn $O(1)$, $O(\log n)$, $O(n)$, $O(n \log n)$, $O(n^2)$.
4. **Learning Cycle for Each Structure:**
   $$\text{Understand Use Case} \longrightarrow \text{Draw Diagrams} \longrightarrow \text{Implement from Scratch} \longrightarrow \text{Analyze Complexity} \longrightarrow \text{Solve Problems} \longrightarrow \text{Compare with STL}$$

---

## 2. STL Containers Overview

### Containers Covered

| Container | Key Operations | Time Complexity | Order Guaranteed? |
|---|---|---|---|
| `std::unordered_set` | `insert`, `erase`, `find`, `count`, `contains` (C++20) | $O(1)$ avg | No |
| `std::unordered_map` | `operator[]`, `insert`, `find`, `count`, `erase` | $O(1)$ avg | No |
| `std::stack` | `push`, `pop`, `top`, `empty`, `size` | $O(1)$ | LIFO (Last-In, First-Out) |
| `std::queue` | `push`, `pop`, `front`, `back`, `empty` | $O(1)$ | FIFO (First-In, First-Out) |
| `std::priority_queue` | `push`, `pop`, `top` | $O(\log n)$ insert/pop | Max-heap by default |

### Important `std::unordered_set` Functions

```cpp
#include <unordered_set>

std::unordered_set<int> numbers;

numbers.insert(10);             // Insert element
numbers.count(10);              // Returns 1 if present, 0 if not
numbers.find(10);               // Returns iterator, numbers.end() if not found
numbers.contains(10);           // C++20 boolean lookup
numbers.erase(10);              // Remove element
numbers.size();                 // Current element count
numbers.empty();                // Returns true if size == 0
numbers.reserve(100);           // Pre-allocate bucket space for ~100 elements
```

**Key Note:** `std::unordered_set` does **not** support index-based access (no `numbers[i]`). Use `std::vector` if index access is needed.

---

## 3. Problem 1: Palindrome Number

### Problem
Determine whether an integer $x$ reads the same forward and backward.

### Discussion & Iterations

#### Initial Attempt
```cpp
bool isPalNum(const int& input) {
    std::string number_in_str = std::to_string(input);
    if (number_in_str.length() == 1) {
        return false; // BUG: 1-digit numbers ARE palindromes
    }
    int leftIndex = 0;
    int rightIndex = static_cast<int>(number_in_str.length() - 1);
    while (leftIndex < rightIndex) {
        if (number_in_str[leftIndex] != number_in_str[rightIndex]) {
            return false;
        } else {
            ++leftIndex;
            --rightIndex;
        }
    }
    return true;
}
```

#### Feedback
1. **Bug:** Single digit numbers (e.g., `7`) read the same in both directions, so `length == 1` should be `true`, not `false`. The loop naturally handles `length == 1` without special logic.
2. **Negative numbers:** Negative numbers start with `'-'` (e.g., `"-121"` vs `"121-"`), so they always fail. Checking `if (input < 0) return false;` up front avoids unnecessary string conversion.
3. **Pass by value:** For primitive types like `int`, `int input` is preferred over `const int&`.

#### Final Solution
```cpp
#include <string>

bool isPalindrome(int x) {
    if (x < 0) return false;

    std::string s = std::to_string(x);
    int left = 0;
    int right = static_cast<int>(s.length()) - 1;

    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}
```

---

## 4. Problem 2: Valid Parentheses & `std::stack`

### Problem
Given a string containing only `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`, determine if the input string is valid.

### Discussion & Iterations

#### Initial Attempt
Tried matching adjacent characters in a loop using `input[i]` and `input[i+1]`.

#### Feedback
Nested brackets like `([])` are valid, but their matching pairs are not adjacent. A **Stack** (LIFO) is needed because the most recently opened bracket must be closed first.

#### How `std::stack` Works
- `push(val)`: Add to top.
- `pop()`: Remove top (does not return a value).
- `top()`: Access top element (must check `!empty()` first!).
- `empty()`: Check if stack has 0 elements.

#### Final Solution (Pattern 1: Push expected closing bracket)
```cpp
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> expected;

    for (char ch : s) {
        if (ch == '(') expected.push(')');
        else if (ch == '[') expected.push(']');
        else if (ch == '{') expected.push('}');
        else {
            if (expected.empty() || expected.top() != ch) return false;
            expected.pop();
        }
    }
    return expected.empty();
}
```

#### Final Solution (Pattern 2: Push opening bracket + `unordered_map`)
```cpp
#include <stack>
#include <string>
#include <unordered_map>

bool isValidMap(const std::string& s) {
    std::stack<char> opened;
    std::unordered_map<char, char> matching = {
        {')', '('}, {']', '['}, {'}', '{'}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            opened.push(ch);
        } else {
            if (opened.empty() || opened.top() != matching[ch]) return false;
            opened.pop();
        }
    }
    return opened.empty();
}
```

---

## 5. Problem 3: Merge Two Sorted Lists

### Problem
Merge two sorted linked lists into one sorted list by splicing together the nodes.

### Discussion & Iterations

#### Initial Attempt
```cpp
while (list1->next != nullptr || list2->next != nullptr) {
    if (list1->val < list2->val) {
        currentNode = list1; // Reassigns pointer variable, doesn't link list!
        list1 = list1->next;
    } ...
}
```

#### Feedback & Key Concepts

1. **`list1->next` in condition:** Crashes if `list1 == nullptr`. Use `while (list1 != nullptr && list2 != nullptr)`.
2. **Connecting nodes:** `currentNode = list1` only changes local pointer. Must write `currentNode->next = list1`, then advance `currentNode = currentNode->next`.
3. **Dummy Node Lifecycle:**
   ```cpp
   ListNode dummy;
   ListNode* current = &dummy;
   ```
   `dummy` lives on the stack during `mergeTwoLists()`. Returning `dummy.next` returns a pointer to the first actual node (on heap/global scope), which remains valid after `dummy` is destroyed. Never return `&dummy`!
4. **Connecting Remainder:**
   ```cpp
   current->next = (list1 != nullptr) ? list1 : list2;
   ```
   When one list is exhausted, attach the rest of the other list in $O(1)$ time.

#### Final Solution
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0, ListNode* n = nullptr) : val(x), next(n) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* current = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != nullptr) ? list1 : list2;
    return dummy.next;
}
```

---

## 6. Problem 4: Remove Duplicates from Sorted Array

### Problem
Given a sorted array `nums`, remove duplicates **in-place** such that each unique element appears only once. Return number of unique elements $k$.

### Discussion & Iterations

#### Initial Attempt
Tried inserting into `std::unordered_set<int>`.

#### Feedback
1. `unordered_set` destroys the sorted relative order.
2. `unordered_set` requires $O(n)$ extra memory (not in-place).
3. The problem statement's underscores `[1, 2, _]` are placeholders representing ignored elements beyond index $k-1$; no need to assign `'_'` characters to `int` vector elements.

#### Final Solution (Two Pointers / Write Index)
```cpp
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 1;

    for (int readIndex = 1; readIndex < static_cast<int>(nums.size()); ++readIndex) {
        if (nums[readIndex] != nums[readIndex - 1]) {
            nums[uniqueIndex] = nums[readIndex];
            ++uniqueIndex;
        }
    }
    return uniqueIndex;
}
```

---

## 7. Problem 5: Remove Element

### Problem
Given an array `nums` and a value `val`, remove all occurrences of `val` **in-place** and return the number of remaining elements $k$.

### Discussion & Iterations

#### Initial Attempt
```cpp
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == val) removed_num++;
    nums[i] = nums[i+1]; // Out-of-bounds read at end!
}
```

#### Feedback
1. `nums[i+1]` reads past the vector boundary on the final iteration.
2. Shifting elements one by one on every match is inefficient ($O(n^2)$) and hard to manage.
3. Return value should be kept count $k$, not removed count.

#### Final Solution (Write Index Pattern)
```cpp
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int writeIndex = 0;

    for (int num : nums) {
        if (num != val) {
            nums[writeIndex] = num;
            ++writeIndex;
        }
    }
    return writeIndex;
}
```

---

## 8. Problem 6: Find Index of First Occurrence (`strStr`)

### Problem
Return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

### Discussion & Iterations

#### How `std::string::substr()` Works
- `s.substr(start, length)`
- `start`: 0-based index.
- `length`: number of characters to copy (defaults to rest of string if omitted).
- **Does not modify original string**; returns a new `std::string`.

#### Common Pitfalls Corrected
1. `std::string sub = sub.substr(...)` — cannot call method on variable currently being declared. Use `haystack.substr(...)`.
2. `needle.size() + 1` — substring length must equal `needle.size()`.
3. Loop boundary: `i <= haystack.size() - needle.size()` (inclusive `<=` so the last substring candidate is checked).

#### Final Solution
```cpp
#include <string>

int strStr(const std::string& haystack, const std::string& needle) {
    if (needle.empty()) return 0;
    if (needle.size() > haystack.size()) return -1;

    for (std::size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
        if (haystack.substr(i, needle.size()) == needle) {
            return static_cast<int>(i);
        }
    }
    return -1;
}
```

---

## 9. Problem 7: Search Insert Position

### Problem
Given a sorted array of distinct integers and a target, return index if target is found, or the insertion index if not. Must be $O(\log n)$.

### Discussion & Iterations

#### Initial Attempt
```cpp
middle = min + max / 2; // Operator precedence bug
looking = !(nums[middle+1] >= target && nums[middle-1] <= target); // Out-of-bounds reads
```

#### Feedback
1. Midpoint formula must be `left + (right - left) / 2` to prevent overflow and ensure correct offset relative to `left`.
2. Avoid accessing `middle - 1` or `middle + 1` directly on `nums` without boundary guards.
3. Standard binary search half-open interval `[left, right)` maintains clear invariant.

#### Final Solution (Binary Search Template)
```cpp
#include <vector>

int searchInsert(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}
```

---

## 10. Problem 8: Length of Last Word

### Problem
Return the length of the last word in a string containing words and spaces.

### Discussion & Iterations

#### How `std::istringstream` Works
```cpp
#include <sstream>

std::istringstream stream(s);
std::string word;

while (stream >> word) {
    // Automatically skips leading/trailing/multiple whitespace
    // 'stream >> word' evaluates to true as long as a word was read
}
```

#### Initial Attempt Fix
`words[words.size()]` is out of bounds because indices range from `0` to `size() - 1`. Use `words.back()` or `words[words.size() - 1]`.

#### Final Solution
```cpp
#include <sstream>
#include <string>

int lengthOfLastWord(const std::string& s) {
    std::istringstream stream(s);
    std::string word;
    std::string lastWord;

    while (stream >> word) {
        lastWord = word;
    }
    return static_cast<int>(lastWord.size());
}
```

---

## 11. Problem 9: Plus One & Integer Conversion

### Problem
Given a large integer represented as `std::vector<int> digits`, increment the integer by one and return resulting digit array.

### Discussion & Iterations

#### Vector to Integer / Integer to Vector Conversion
- **Vector to Int:**
  ```cpp
  int result = 0;
  for (int digit : digits) {
      result = result * 10 + digit;
  }
  ```
- **Int to Vector:**
  ```cpp
  std::vector<int> digits;
  while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
  }
  std::reverse(digits.begin(), digits.end());
  ```
- **Why this fails for "Plus One":** Overflow! Input vector can represent numbers with 100+ digits, far exceeding `uint64_t`.

#### Digits Loop & Carry Logic

```cpp
std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> result = digits;

    // Start from least significant digit (rightmost)
    for (int i = static_cast<int>(digits.size() - 1); i >= 0; --i) {
        if (digits[i] < 9) {
            result[i] = digits[i] + 1;
            return result; // No carry needed, stop early
        }
        result[i] = 0; // Carry continues to next left digit
    }

    // All digits were 9 (e.g., [9,9,9] -> [1,0,0,0])
    std::vector<int> newResult(digits.size() + 1, 0);
    newResult[0] = 1;
    return newResult;
}
```

#### Tracing Trace Cases
- `{1, 2, 3}` $\rightarrow$ `digits[2]` is $3 < 9 \rightarrow$ `{1, 2, 4}` (stops immediately)
- `{1, 8, 9}` $\rightarrow$ `digits[2]` becomes $0$, `digits[1]` is $8 < 9 \rightarrow$ `{1, 9, 0}` (stops at index 1)
- `{9, 9, 9}` $\rightarrow$ all become $0$, loop ends, returns `{1, 0, 0, 0}`

---

## Summary of Core Principles Learned

1. **Pass-by-value vs Pass-by-reference:** Pass primitive scalar types (`int`, `char`) by value; pass containers (`std::vector`, `std::string`) by `const &` (read-only) or `&` (in-place modification).
2. **Bounds Checking:** Always verify `index >= 0` and `index < size()`. Never access `v[v.size()]`.
3. **Write Pointer Pattern:** For array in-place modifications, maintain a `writeIndex` alongside a `readIndex`.
4. **Stack Safe Access:** Check `!stack.empty()` before calling `stack.top()` or `stack.pop()`.
5. **Dummy Nodes:** Use stack-allocated `ListNode dummy` when constructing dynamic linked lists to avoid special head-pointer conditional checks.
