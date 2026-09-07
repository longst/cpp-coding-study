# Length of Last Word

## Pattern

String parsing.

## Key idea

Use `std::istringstream` to read words separated by whitespace, and keep only the latest word.

## Correct solution

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

## Common mistakes

- Using `words[words.size()]`, which is out of bounds.
- Storing all words when only the last one is needed.

## Complexity

- Time: `O(n)`
- Space: `O(1)` excluding the current word storage.

