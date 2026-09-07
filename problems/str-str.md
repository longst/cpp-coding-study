# Find the Index of the First Occurrence in a String

## Pattern

Substring checking.

## Key idea

Try each possible starting index and compare `haystack.substr(i, needle.size())` with `needle`.

## Correct solution

```cpp
#include <string>

int strStr(const std::string& haystack, const std::string& needle) {
    if (needle.empty()) {
        return 0;
    }

    if (needle.size() > haystack.size()) {
        return -1;
    }

    for (std::size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
        if (haystack.substr(i, needle.size()) == needle) {
            return static_cast<int>(i);
        }
    }

    return -1;
}
```

## Common mistakes

- Calling `substr` on the variable being declared.
- Using `needle.size() + 1`.
- Missing the last valid starting position by using `<` instead of `<=`.

## Complexity

- Time: `O(n * m)` for this simple version.
- Space: `O(m)` for each substring copy.

