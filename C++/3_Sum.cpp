#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    // Sort the array to facilitate two-pointer approach and duplicate handling
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    // Traverse the array
    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicates for the first element of the triplet
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = nums.size() - 1;

        // Two-pointer approach for the remaining two elements
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});

                // Skip duplicates for the second element
                while (j < k && nums[j] == nums[j + 1]) j++;
                // Skip duplicates for the third element
                while (j < k && nums[k] == nums[k - 1]) k--;

                j++;
                k--;
            }
            else if (sum < 0) {
                j++; // We need a larger sum, so move the left pointer
            }
            else {
                k--; // We need a smaller sum, so move the right pointer
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets with sum zero are:" << endl;
    for (const auto &triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
