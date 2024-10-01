#include <bits/stdc++.h>
using namespace std;

void binary_search(vector<int>& array,int k)
{
 int low=0,high=array.size()-1;
 while(low<=high)
 {
    int mid=(high+low)>>1;
    if(array[mid]==k)
    {
        cout<<"Element is found in the array"<<endl;
        return;
    }
    else if(array[mid]>k)
    {
        high=mid-1;
    }
    else {
        low=mid+1;
    }

 }
 cout<<"Element is not found in the given array."<<endl;
}



void printVector(const vector<int>& array)
{
    for (int i = 0; i < array.size(); i++) cout << array[i] << " ";
    cout << endl;
}



int main() {
    int numberOfElements,k;
    cout << "Enter the number of elements in the array: ";
    cin >> numberOfElements;
    vector<int> array(numberOfElements);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < numberOfElements; i++) cin >> array[i];
    cout<< "Given array is: ";
    printVector(array);
    cout<<"enter the no. to be found";
    cin>>k;
    sort(array.begin(),array.end());
    binary_search(array,k);
    
    return 0;

}
