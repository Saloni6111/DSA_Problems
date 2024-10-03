/*  Linear Search Algorithm : 
        (i) This is the simplest searching algorithm.
        (ii) It checks each element of the array until the desired element is found. 

        Problem Statement : To check if number is present in the array or not using linear search
        Test Case : 81, 23, 45, 30, 70, 11, 15
        Target : 70
        Output : Element found at index 4
*/

#include <stdio.h>

// This is linear serach algorithm's main logic
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {81, 23, 45, 30, 70, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int result = linearSearch(arr, size, key);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
