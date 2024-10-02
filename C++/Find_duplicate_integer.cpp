#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size() - 1;
        
        for (int i = 0; i <= n; i++) {
            int k = nums[i];
            nums[k % (n + 2)] += (n + 2);
        }
        
        int ans = -1;
        for (int i = 0; i <= n; i++) {
            if (nums[i] / (n + 2) >= 2) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums;

    // Example input
    nums = {3, 1, 3, 4, 2};  // Duplicate is 3
    int duplicate = solution.findDuplicate(nums);

    std::cout << "The duplicate number is: " << duplicate << std::endl;

    return 0;
}
