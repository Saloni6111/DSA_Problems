class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        vector<int> arr(encoded.size() + 1);
        arr[0] = first;
        for(int i = 1; i < encoded.size() + 1; i++){
            arr[i] = encoded[i-1] ^ arr[i-1];
        }
        return arr;
    }
};