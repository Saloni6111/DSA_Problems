#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans; // Return the result once the pair is found
            }
            map[nums[i]] = i;
        }
        return ans;
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
