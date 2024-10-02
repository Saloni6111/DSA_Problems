#include <bits/stdc++.h>
using namespace std;



void maxElement(vector<int>& array, int n)
{
    int max_element=array[0];

    for(int i=1;i<=n;i++)
      if(max_element<array[i])
        max_element=array[i];
    
     cout<<"Maximum Element in the array is : "<<max_element;
}

void printVector(const vector<int>& array)
{
    for (int i = 0; i < array.size(); i++) cout << array[i] << " ";
    cout << endl;
}


int main() {
    int numberOfElements;
    cout << "Enter the number of elements in the array: ";
    cin >> numberOfElements;
    vector<int> array(numberOfElements);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < numberOfElements; i++) cin >> array[i];
    cout<< "Given vector is: ";
    printVector(array);
    maxElement(array, numberOfElements - 1);
    
    return 0;

}



