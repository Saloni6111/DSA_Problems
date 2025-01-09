class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int mxh = 1, mxv = 1,curr = 1;
        
        for(int i=1; i<h; i++){
            if(hBars[i] == hBars[i-1] + 1){
                curr++;
            }
            else curr = 1;
            mxh = max(mxh,curr);
        }

        curr = 1;
        for(int i=1; i<v; i++){
            if(vBars[i] == vBars[i-1] + 1){
                curr++;
            }
            else curr = 1;
            mxv = max(mxv,curr);
        }
        int mini = min(mxh+1,mxv+1);

        return mini * mini;
    }
};