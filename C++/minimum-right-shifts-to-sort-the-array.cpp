class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (is_sorted(nums.begin(), nums.end()))
                return i;
            int last_element = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), last_element);
        }
        return -1;
    }
};