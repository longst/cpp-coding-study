# Plus One

## Pattern

Digit array, carry handling from right to left.

## Key idea

Do not convert the whole array to an integer because the number may be too large. Start from the last digit:

- If the digit is less than `9`, add one and return.
- If the digit is `9`, set it to `0` and continue carrying to the left.
- If all digits are `9`, create a new vector with leading `1`.

## Correct solution

```cpp
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> result = digits;

    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            result[i] = digits[i] + 1;
            return result;
        }

        result[i] = 0;
    }

    std::vector<int> newResult(digits.size() + 1, 0);
    newResult[0] = 1;
    return newResult;
}
```

## Common mistakes

- Starting from `digits.size()` instead of `digits.size() - 1`.
- Converting the full digit array into `int` or `size_t`.
- Forgetting the all-9 case, e.g. `[9,9,9] -> [1,0,0,0]`.

## Complexity

- Time: `O(n)`
- Space: `O(n)` for the copied result in this version.

