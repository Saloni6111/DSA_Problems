/******************************************************************************

Given a number N print the first N numbers of Fibonacci sequence.
Approach: Bottom up approach
1. Initialize the vector array with the first two numbers as 0 and 1;
2. Print the first two numbers
3. Compute the next number as the sum of the previous two numbers
4. Repeat steps 2 and 3 until the desired number of terms is reached;
Time Complexity: O(n)
Space Complexity: O(n)


*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printFibboSeq(int n){
     vector<int>fibbo(n,0);
     fibbo[1]=1;
     for(int i=2;i<fibbo.size();i++){
         fibbo[i]=fibbo[i-1]+fibbo[i-2];
     }
     for(int num:fibbo)
     cout<<num<<",";
     
}
int main()
{   int n;
    cout<<"Please enter the number:";
    cin>>n;
    printFibboSeq(n);
}