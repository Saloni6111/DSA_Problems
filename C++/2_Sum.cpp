#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int y = target - nums[i];
            if(mp.count(y)){
                return {mp[y],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    // Sample input
    vector<int> nums = {2, 7, 11, 15}; // Make sure you're using C++11 or later
    int target = 9;

    // Create an instance of the Solution class
    Solution solution;

    // Call the twoSum function
    vector<int> result = solution.twoSum(nums, target);

    // Output the result
    if (!result.empty())
    {
        cout << "Indices of the numbers that add up to the target: ";
        cout << result[0] << " " << result[1] << endl;
    }
    else
    {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}
