# Search Insert Position

## Pattern

Binary search.

## Key idea

Find the first index where `nums[index] >= target`.

## Correct solution

```cpp
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
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

## Common mistakes

- Using `middle = left + right / 2`.
- Accessing `middle + 1` or `middle - 1`.
- Updating the wrong boundary.

## Complexity

- Time: `O(log n)`
- Space: `O(1)`

