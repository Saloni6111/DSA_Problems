#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // Function to find indices of the two numbers such that they add up to target
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // Map to store number and its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate complement
            
            // Check if complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // Return indices
            }
            
            numMap[nums[i]] = i; // Store the index of the current number
        }
        
        return {}; // Return empty vector if no solution is found
    }

    // Helper function to print the result
    void printResult(const std::vector<int>& result) {
        if (result.empty()) {
            std::cout << "No solution found" << std::endl;
        } else {
            std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
        }
    }

    // Helper function to test the twoSum function with various test cases
    void runTests() {
        // Test case 1
        std::vector<int> nums1 = {2, 7, 11, 15};
        int target1 = 9;
        std::cout << "Test Case 1: ";
        printResult(twoSum(nums1, target1)); // Expected output: Indices: 0, 1

        // Test case 2
        std::vector<int> nums2 = {3, 2, 4};
        int target2 = 6;
        std::cout << "Test Case 2: ";
        printResult(twoSum(nums2, target2)); // Expected output: Indices: 1, 2

        // Test case 3
        std::vector<int> nums3 = {3, 3};
        int target3 = 6;
        std::cout << "Test Case 3: ";
        printResult(twoSum(nums3, target3)); // Expected output: Indices: 0, 1

        // Additional test case
        std::vector<int> nums4 = {1, 5, 3, 8};
        int target4 = 6;
        std::cout << "Test Case 4: ";
        printResult(twoSum(nums4, target4)); // Expected output: Indices: 0, 2
    }
};

int main() {
    Solution sol;
    sol.runTests(); // Run all the test cases
    return 0;
}
