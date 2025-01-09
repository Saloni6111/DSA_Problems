class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        int sqrtN = sqrt(n);
        for(int i=2; i<=sqrtN; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<8; k++){
                    int digit = mat[i][j];
                    int row = i + drow[k];
                    int col = j + dcol[k];
                    while(row>=0 && row<n && col>=0 && col<m){
                        digit = digit*10 + mat[row][col];
                        if(digit>10){
                            if(isPrime(digit)) mp[digit]++;
                        }
                        row += drow[k];
                        col += dcol[k];
                    }
                }
            }
        }
        if(mp.empty()) return -1;
        int freq = 0;
        int ans;
        for(auto it: mp){
            if(it.second >= freq){
                if(freq == it.second) ans = max(ans, it.first);
                else{
                    freq = it.second;
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};