#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the total number of continuous subarrays whose sum equals k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // Base case: sum of 0 occurs once
    int currentSum = 0;
    int count = 0;
    
    for (int num : nums) {
        currentSum += num;
        // Check if (currentSum - k) exists in the prefixSumCount
        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }
        // Store the currentSum in the map
        prefixSumCount[currentSum]++;
    }
    
    return count;
}

int main() {
    int n, k;
    
    // Take input for the size of the array and the target sum 'k'
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    
    // Take input for the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Take input for the target sum 'k'
    cout << "Enter the value of k: ";
    cin >> k;
    
    // Call the function to get the result and print it
    int result = subarraySum(nums, k);
    cout << "Total number of continuous subarrays whose sum equals " << k << ": " << result << endl;

    return 0;
}

/*
Example test cases:

Test Case 1:
Input:
n = 8
nums[8] = [3,4,7,2,-3,1,4,2]
k = 7

Output:
Total number of continuous subarrays whose sum equals 7: 4
Subarrays: 
[3, 4]
[7]
[4, 7, 2, -3, 1]
[7]

Test Case 2:
Input:
n = 3
nums[3] = [1,1,1]
k = 2

Output:
Total number of continuous subarrays whose sum equals 2: 2
Subarrays:
[1, 1]
[1, 1]

Test Case 3:
Input:
n = 3
nums[3] = [1, -1, 0]
k = 0

Output:
Total number of continuous subarrays whose sum equals 0: 3
Subarrays:
[1, -1]
[-1, 0]
[1, -1, 0]

Test Case 4:
Input:
n = 4
nums[4] = [1, 2, 3, 4]
k = 3

Output:
Total number of continuous subarrays whose sum equals 3: 2
Subarrays:
[3]
[1, 2]
*/
