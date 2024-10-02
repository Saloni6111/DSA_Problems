#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> umap;

        for (const auto& x : strs) {
            std::string word = x;
            // Sort the word to create a key
            std::sort(word.begin(), word.end());
            // Group anagrams together
            umap[word].push_back(x);
        }
        
        std::vector<std::vector<std::string>> ans;

        // Populate the result vector with grouped anagrams
        for (const auto& x : umap) {
            ans.push_back(x.second);
        }

        return ans;
    }
};

// Example usage
#include <iostream>

int main() {
    Solution solution;
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(input);

    // Print the result
    for (const auto& group : result) {
        std::cout << "[ ";
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
