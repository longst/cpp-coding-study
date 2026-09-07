#include <iostream>
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

int main() {
    std::cout << lengthOfLastWord("Hello World") << '\n';                 // 5
    std::cout << lengthOfLastWord("   fly me   to   the moon  ") << '\n'; // 4
    std::cout << lengthOfLastWord("luffy is still joyboy") << '\n';       // 6
    return 0;
}
