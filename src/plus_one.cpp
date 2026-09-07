#include <iostream>
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

void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 8, 9};
    std::vector<int> c = {9, 9, 9};

    printVector(plusOne(a));
    printVector(plusOne(b));
    printVector(plusOne(c));

    return 0;
}

