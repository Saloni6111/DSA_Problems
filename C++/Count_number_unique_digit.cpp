#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // Array to store the number of unique digit numbers for different digits
        vector<int> vec(9);
        
        // Base case: when n = 0, the only number is 0 itself
        if (n == 0)  
            return 1;
        
        // Initialize the first two cases
        vec[0] = 10;        // 10 numbers (0 to 9) for n = 1
        vec[1] = 9 * 9;     // 9 options for the first digit (1 to 9), 9 for the second (0 to 9 except first digit)
        
        // Calculate for higher digit numbers
        vec[2] = vec[1] * 8;
        vec[3] = vec[2] * 7;
        vec[4] = vec[3] * 6;
        vec[5] = vec[4] * 5;
        vec[6] = vec[5] * 4;
        vec[7] = vec[6] * 3;
        vec[8] = vec[7] * 2;
        
        // Sum all valid results for unique digit numbers up to n digits
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += vec[i];
        }
        
        return sum;
    }
};

int main() {
    Solution solution;
    
    // Test the function with different values of n
    int n;
    cout << "Enter a value for n (0-8): ";
    cin >> n;
    
    // Output the result
    cout << "Count of numbers with unique digits for n = " << n << ": " 
         << solution.countNumbersWithUniqueDigits(n) << endl;
    
    return 0;
}
