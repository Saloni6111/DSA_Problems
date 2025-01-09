class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,avl=0;
        for(auto i:moves){
            if(i=='L'){
                l++;
            }
            else if(i=='R'){
                r++;
            }
            else{
                avl++;
            }
        }
        if(l>r){
            l+=avl;
            return l-r;
        }
        else if(r>l){
            r+=avl;
            return r-l;
        }
        return avl;
    }
};