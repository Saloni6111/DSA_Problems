// Special Matrix
/*
A matrix is called special if the sum of each row and the sum of each column is the same. Given a square matrix A of dimensions N×N. Find the minimum number of operations required to make it special. 
In one operation you can choose any number in the matrix and increase it by 1.
*/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int minOperations(vector<vector<int>> &mat, int n){
     vector<int> sumRow(n, 0);
     vector<int> sumCol(n, 0);
     
     for(int r = 0; r < n; r++){
          for(int c = 0; c < n; c++){
                    sumRow[r] += mat[r][c];
                    sumCol[c] += mat[r][c];
          }
     }
     int maxVal = max(*max_element(sumRow.begin(), sumRow.end()),
                    *max_element(sumCol.begin(), sumCol.end()));
  

    int i = 0, j = 0;
    int count_op = 0;
    while(i < n && j < n){
          int diff = min(maxVal - sumRow[i], maxVal - sumCol[j]);
          mat[i][j] += diff;
          sumRow[i] += diff;
          sumCol[j] += diff;
          count_op += diff;
          if(sumRow[i] == maxVal) i++;
          if(sumCol[j] == maxVal) j++;
    }
    return count_op;
}
int main() {
    eff;
    int n;
    cin>>n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(int r = 0; r < n; r++){
      for(int c = 0; c < n; c++){
        cin>>mat[r][c];
      }
    }
    cout<<minOperations(mat, n)<<endl;
    return 0;

}
