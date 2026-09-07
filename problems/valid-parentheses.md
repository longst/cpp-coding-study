# Valid Parentheses

## Pattern

Stack.

## Key idea

Use a stack to remember the expected closing brackets. When reading an opening bracket, push the matching closing bracket. When reading a closing bracket, it must match the top of the stack.

## Correct solution

```cpp
#include <stack>
#include <string>

bool validParentheses(const std::string& input) {
    std::stack<char> expected;

    for (char ch : input) {
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
```

## Common mistakes

- Only checking adjacent characters.
- Calling `top()` on an empty stack.
- Forgetting to check that the stack is empty at the end.

## Complexity

- Time: `O(n)`
- Space: `O(n)`

