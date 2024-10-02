#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> mp;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                mp.push(c);
            } else {
                if (mp.empty()) {
                    return false;
                }
                if ((c == ')' && mp.top() == '(') ||
                    (c == ']' && mp.top() == '[') ||
                    (c == '}' && mp.top() == '{')) {
                    mp.pop();
                } else {
                    return false; 
                }
            }
        }
        
        return mp.empty();
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
