#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> sample;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k= nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        for(auto store:s){
            sample.push_back(store);
        }
        return sample;
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
