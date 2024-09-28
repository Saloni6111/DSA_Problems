#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& array, int leftIndex, int midIndex, int rightIndex) {

    int leftSize = midIndex - leftIndex + 1;

    int rightSize = rightIndex - midIndex;


    vector<int> leftArray(leftSize);

    vector<int> rightArray(rightSize);


    for (int i = 0; i < leftSize; i++) leftArray[i] = array[leftIndex + i];

    for (int j = 0; j < rightSize; j++) rightArray[j] = array[midIndex + 1 + j];

    int i = 0, j = 0;
    int k = leftIndex;

    while (i < leftSize && j < rightSize)
    {

        if (leftArray[i] <= rightArray[j])

        {

            array[k] = leftArray[i];

            i++;

        }

        else

        {

            array[k] = rightArray[j];

            j++;

        }

        k++;

    }



    while (i < leftSize)

    {

        array[k] = leftArray[i];

        i++;

        k++;

    }



    while (j < rightSize)

    {

        array[k] = rightArray[j];

        j++;

        k++;


    }

}



void mergeSort(vector<int>& array, int leftIndex, int rightIndex)
{

    if (leftIndex >= rightIndex) return;


    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(array, leftIndex, midIndex);

    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);

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


    mergeSort(array, 0, numberOfElements - 1);


    cout << "Sorted vector is: ";

    printVector(array);


    return 0;

}



