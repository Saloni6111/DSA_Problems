class Solution {
public:
    double trimMean(vector<int>& arr) {

        int n = arr.size();

        int to_del = (n * 5) / 100;
        // this must be an integer as it denotes the number of elements that given array contains in its 5 percent!!

        double sum = 0;
        double mean = 0;
        int cnt = 0;
        // storing the elements of which we need to consider the mean!!

        sort(arr.begin(), arr.end());

        for(int i = to_del; i < n-to_del; i++){
            // we will trim 5 percent of elements from both the ends, thus getting the sum we need to consider to find mean
            // we also have variable cnt here, which will keep count of elements being considered for mean!!

            sum += arr[i];
            cnt++;
        }

        mean = sum / cnt;
        
        return mean;
        
    }
};