#include <iostream>
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

int main() {
    std::cout << strStr("sadbutsad", "sad") << '\n';   // 0
    std::cout << strStr("leetcode", "leeto") << '\n';  // -1
    std::cout << strStr("hello", "ll") << '\n';        // 2
    return 0;
}
