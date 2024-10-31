#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stack;
        
        for (char c : s) {
            switch (c) {
                case '(': case '[': case '{':
                    stack.push(c);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(') return false;
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[') return false;
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{') return false;
                    stack.pop();
                    break;
                default:
                    return false; // Invalid character
            }
        }
        
        return stack.empty();
    }
};

// Example usage
int main() {
    Solution solution;
    std::string input;

    // Test with a few examples
    std::cout << "Enter a string of parentheses: ";
    std::cin >> input;

    if (solution.isValid(input)) {
        std::cout << "The string is valid.\n";
    } else {
        std::cout << "The string is not valid.\n";
    }

    return 0;
}
