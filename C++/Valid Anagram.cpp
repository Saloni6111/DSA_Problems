/*problem statment-Given two strings s and t, return true if t is an anagramof s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false */

//SOLUTION CODE USING UNORDERED_MAP
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check if the lengths of the strings are different
        if (s.length() != t.length()) {
            return false; // Not an anagram if lengths differ
        }

        // Create an unordered map with characters as keys and their frequencies as values
        unordered_map<char, int> mpp;

        // Count characters in the first string
        for (char c : s) {
            mpp[c]++;
        }

        // Decrease the count based on characters in the second string
        for (char c : t) {
            mpp[c]--;
        }

        // Check if all counts are zero
        for (auto it : mpp) {
            if (it.second != 0) { // If any character frequency is not zero, it's not an anagram
                return false;
            }
        }
        
        return true; // The strings are anagrams
    }
};

int main() {
    Solution obj;

    // Test case 1
    //Expected output true
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << boolalpha << obj.isAnagram(s1, s2) << endl; // Checking if s1 is an anagram of s2

    // Test case 2
    //Expected output false 
    s1 = "rat";
    s2 = "car";
    cout << boolalpha << obj.isAnagram(s1, s2) << endl; // Checking if s1 is an anagram of s2

    return 0;
}