# Remove Duplicates from Sorted Array

## Pattern

Two pointers / write index.

## Key idea

Because the array is sorted, duplicates are adjacent. Keep one write index for the next unique value.

## Correct solution

```cpp
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

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

## Common mistakes

- Passing the vector by value instead of reference.
- Using `unordered_set`, which does not preserve order and is not in-place.
- Trying to fill the ignored positions with `_`.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

