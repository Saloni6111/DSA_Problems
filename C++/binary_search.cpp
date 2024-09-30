#include <bits/stdc++.h>
using namespace std;

void binary_search()



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
    binary_search(array,k);
    
    return 0;

}
