#include <iostream>
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

int main() {
    std::vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    std::cout << "k1 = " << k1 << ", elements: ";
    for (int i = 0; i < k1; ++i) std::cout << nums1[i] << ' ';
    std::cout << '\n';

    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);
    std::cout << "k2 = " << k2 << ", elements: ";
    for (int i = 0; i < k2; ++i) std::cout << nums2[i] << ' ';
    std::cout << '\n';

    return 0;
}
