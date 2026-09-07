#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> expected;

    for (char ch : s) {
        if (ch == '(') {
            expected.push(')');
        } else if (ch == '[') {
            expected.push(']');
        } else if (ch == '{') {
            expected.push('}');
        } else {
            if (expected.empty() || expected.top() != ch) {
                return false;
            }
            expected.pop();
        }
    }

    return expected.empty();
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isValid("()") << '\n';       // true
    std::cout << isValid("()[]{}") << '\n';   // true
    std::cout << isValid("(]") << '\n';       // false
    std::cout << isValid("([])") << '\n';     // true
    std::cout << isValid("([)]") << '\n';     // false
    return 0;
}
