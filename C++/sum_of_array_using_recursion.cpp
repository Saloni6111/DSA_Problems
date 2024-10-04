// Question: Find the sum of the elements of an array using recursion.

#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    if (n <= 0)  // Base case
        return 0; 
    return sum(arr, n - 1) + arr[n - 1]; // Recursive call
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;      // Input the number of elements in the array
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];     // Input the elements of the array
    cout << "Sum of the elements of the array: " << sum(arr, n);    // Output the sum of the elements of the array
    return 0;
}

/*
**Explanation:**

1. Function Declaration (sum)

The function sum is declared with two parameters:
arr[]: the array containing the elements.
n: the number of elements in the array or the current size of the array for each recursive call.

2. Base Case (if (n <= 0))

Recursion needs a stopping condition to avoid infinite calls. The base case here is when n <= 0, meaning there are no more elements to sum up.
If this condition is true, the function returns 0 because there are no elements left to sum. This terminates the recursion.

3. Recursive Call (sum(arr, n - 1) + arr[n - 1])

The key idea in recursion is to break the problem into smaller parts. Here, we make a recursive call by reducing the size of the array by 1 (n - 1).
Each recursive call sums up the element arr[n - 1] (the last element in the current array) and adds it to the sum of the remaining array (sum(arr, n - 1)).
This continues until n becomes 0, at which point the recursion stops, and the base case returns 0.

4. Main Function

Input:
The program first asks the user for the number of elements (n) in the array.
Then, the user is prompted to enter the elements of the array one by one.
Output:
The sum function is called with the entire array and its size (n), and the result (sum of the array elements) is printed. 


## Example Walkthrough:
If the input is:

n = 4
arr = [1, 2, 3, 4]

The recursive process looks like this:

sum(arr, 4) = sum(arr, 3) + arr[3] = sum(arr, 3) + 4
sum(arr, 3) = sum(arr, 2) + arr[2] = sum(arr, 2) + 3
sum(arr, 2) = sum(arr, 1) + arr[1] = sum(arr, 1) + 2
sum(arr, 1) = sum(arr, 0) + arr[0] = sum(arr, 0) + 1
sum(arr, 0) = 0 (base case)

Finally, summing up all the values:
0 + 1 + 2 + 3 + 4 = 10


*/