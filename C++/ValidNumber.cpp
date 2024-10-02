#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // Strip whitespace from both ends (if needed)
        int n = s.length();
        int i = 0, j = n - 1;

        // Remove leading and trailing whitespaces
        while (i < n && s[i] == ' ') i++;
        while (j >= 0 && s[j] == ' ') j--;

        if (i > j) return false;  // If the string only contains whitespace
        
        bool has_digit = false, has_dot = false, has_e = false, has_sign = false;
        
        for (int k = i; k <= j; ++k) {
            char ch = s[k];

            // If the character is a digit
            if (isdigit(ch)) {
                has_digit = true;
            }
            // If the character is a '+' or '-'
            else if (ch == '+' || ch == '-') {
                // The sign can only appear at the start or after 'e'/'E'
                if (k > i && s[k-1] != 'e' && s[k-1] != 'E') return false;
            }
            // If the character is a decimal point '.'
            else if (ch == '.') {
                // There can be only one dot, and it cannot appear after 'e'/'E'
                if (has_dot || has_e) return false;
                has_dot = true;
            }
            // If the character is 'e' or 'E'
            else if (ch == 'e' || ch == 'E') {
                // There can be only one 'e', and it must come after a digit
                if (has_e || !has_digit) return false;
                has_e = true;
                has_digit = false;  // Need digits after 'e'
            }
            // If the character is anything else
            else {
                return false;  // Invalid character
            }
        }

        // Return true only if there's at least one digit
        return has_digit;
    }
};

// Driver code to test the isNumber function
int main() {
    Solution solution;

    // Test cases
    string test_cases[] = {"0", "e", ".", "2e10", "-90E3", "99e2.5", "--6", "53.5e93", "95a54e53"};
    bool expected_results[] = {true, false, false, true, true, false, false, true, false};

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        string test = test_cases[i];
        bool expected = expected_results[i];
        bool result = solution.isNumber(test);
        cout << "Test: " << test << "\nExpected: " << (expected ? "true" : "false") << "\nResult: " << (result ? "true" : "false") << endl;
        cout << (expected == result ? "Passed" : "Failed") << "\n\n";
    }

    return 0;
}
