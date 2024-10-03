/*  Binary Search Algorithm : 
        (i) Binary search is more efficient but works only on sorted arrays.
        (ii) It divides the array in half and eliminates half of the remaining elements with each comparison.

        Problem Statement : To check if number is present in the array or not using binary search
        Test Case : 10, 23, 45, 70, 75, 80
        Target : 70
        Output : Element found at index 3
*/


#include <stdio.h>

// This is binary serach algorithm's main logic 
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // FInd the middle of the array
        
        if (arr[mid] == key) { // Check if middle is equal to target
            return mid;
        } else if (arr[mid] < key) { // Check if middle is less than target
            low = mid + 1;
        } else { // if middle is greater than target
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 23, 45, 70, 75, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int result = binarySearch(arr, size, key);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}