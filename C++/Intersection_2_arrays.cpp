#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Set allows to discard duplicates
    unordered_set<int> set1(nums1.begin(), nums1.end());
    // Ensure we don't add duplicates
    // Could potentially create set for nums2 and directly insert into a vector
    unordered_set<int> resultSet;
    for (int num : nums2) {
        if (set1.find(num) != set1.end()) {
            resultSet.insert(num);
        }
    }
    return vector<int>(resultSet.begin(), resultSet.end());
}

// Test case
int main() {
    // Change vectors for your own test cases
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = intersection(nums1, nums2);
    if (!result.empty())
    {
        cout << "Intersection: ";
        for (int num : result) {
            cout << num << " ";
        }
    }
    else
    {
        cout << "No intersection";
    }
    return 0;
}

// Test case 1: nums1:{1, 2, 2, 1}, nums2:{2, 2} 
// Expected output: [1, 2]


// Test case 2: nums1:{}, nums2:{} 
// Expected output: [] or No intersection