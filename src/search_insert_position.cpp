#include <iostream>
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

int main() {
    std::vector<int> nums = {1, 3, 5, 6};

    std::cout << searchInsert(nums, 5) << '\n'; // 2
    std::cout << searchInsert(nums, 2) << '\n'; // 1
    std::cout << searchInsert(nums, 7) << '\n'; // 4
    std::cout << searchInsert(nums, 0) << '\n'; // 0

    return 0;
}
