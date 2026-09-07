# Remove Element

## Pattern

Write index.

## Key idea

Scan every number. If it is not equal to `val`, write it into the next valid position.

## Correct solution

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

## Common mistakes

- Returning the number of removed elements instead of kept elements.
- Writing `nums[writeIndex] = val` instead of `nums[writeIndex] = num`.
- Shifting with `nums[i] = nums[i + 1]`, which can read out of bounds.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

