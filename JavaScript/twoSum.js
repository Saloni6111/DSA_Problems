
/*
Problem: Find the Pair of Numbers that Sum to a Target

Test Case 1:
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9 

Test Case 2:
Input: nums = [2, 7, 11, 15], target = 17
Output: [0, 3]
Explanation: nums[0] + nums[3] = 2 + 15 = 17 

*/

function twoSum(nums, target) {

    // Step 1: Create a hash map to store numbers and their indices
    const numIndices = {};

    // Step 2: Loop through the array
    for (let i = 0; i < nums.length; i++) {

        // Step 3: Calculate the complement (target - current number)
        const complement = target - nums[i];

        // Step 4: Check if complement exists in the hash map
        if (numIndices[complement] !== undefined) {
            return [numIndices[complement], i]; // Return indices of the two numbers
        }

        // Step 5: Store the current number with its index in the hash map
        numIndices[nums[i]] = i;
    }

    // If no solution is found, return null (though the problem assumes exactly one solution)
    return null;
}

// Example usage:
const nums = [2, 7, 11, 15];
const target = 9;

console.log(twoSum(nums, target)); // Output: [0, 1]
