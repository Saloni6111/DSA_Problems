#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
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
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}