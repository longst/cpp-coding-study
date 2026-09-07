#include <iostream>
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

int main() {
    std::vector<int> nums1 = {3, 2, 2, 3};
    int k1 = removeElement(nums1, 3);
    std::cout << "k1 = " << k1 << ", elements: ";
    for (int i = 0; i < k1; ++i) std::cout << nums1[i] << ' ';
    std::cout << '\n';

    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = removeElement(nums2, 2);
    std::cout << "k2 = " << k2 << ", elements: ";
    for (int i = 0; i < k2; ++i) std::cout << nums2[i] << ' ';
    std::cout << '\n';

    return 0;
}
