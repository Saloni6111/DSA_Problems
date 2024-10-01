#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> X;
    // Merge the two arrays into X
    for (int i = 0; i < n; i++) {
        X.push_back(nums1[i]); //pushing numbers in the nums1 vector;
    }
    for (int i = 0; i < m; i++) {
        X.push_back(nums2[i]); //pushing numbers in the nums2 vector;
    }
    // Sort the merged array
    sort(X.begin(), X.end()); // sorting
    int total = X.size();
    // Find the median
    if (total % 2 == 1) {
        return (double)(X[total / 2]);  //taking median acc to the number of elements present i.e if its odd or even
    } else {
        int mid1 = X[total / 2 - 1];
        int mid2 = X[total / 2];
        return ((double)(mid1) + (double)(mid2)) / 2.0;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    int m;
    cout << "Enter the number of elements in the second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
  // Find and print the median.
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median of the two sorted arrays is: " << median << endl;

    return 0;
}



// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.