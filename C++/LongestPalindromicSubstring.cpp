#include <iostream>
#include <string>
using namespace std;
/**
 * @brief
 * author @albinsabu2023
 * time complexity O(n*n)
 * space complexity O(n)
 *
 * approach:expand around index
 * two cases
 * odd length palindrome (single center index)
 * even length palindrome (two center index)
 *
 */
class Solution
{
public:
    // Function to expand around the center and find the palindrome
    string expand(string s, int left, int right)
    {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1); // return the palindromic substring
    }

    // Function to find the longest palindromic substring
    string longestPalindrome(string s)
    {
        if (s.length() == 1)
            return s; // if the string has only one character, it's the longest palindrome
        int n = s.length();
        string ans = ""; // variable to store the longest palindrome

        for (int i = 0; i < n - 1; i++)
        {
            // Check for odd-length palindromes (centered at one character)
            string oddlength = expand(s, i, i);
            if (oddlength.length() > ans.length())
            {
                ans = oddlength;
            }

            // Check for even-length palindromes (centered between two characters)
            string evenlength = expand(s, i, i + 1);
            if (evenlength.length() > ans.length())
            {
                ans = evenlength;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string result = sol.longestPalindrome(s);
    cout << "Longest palindromic substring is: " << result << endl;

    return 0;
}
