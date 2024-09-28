import java.util.Scanner;

class Solution {
    // Function to sort an array using the quicksort algorithm.
    static void quickSort(int arr[], int low, int high) {
        if (low < high) {
            // Find pivot index
            int pivotInd = partition(arr, low, high);
            // Recursively sort elements before and after the partition
            quickSort(arr, low, pivotInd - 1);
            quickSort(arr, pivotInd + 1, high);
        }
    }

    // Function to partition the array
    static int partition(int arr[], int low, int high) {
        int pivot = arr[low];
        int left = low;
        int right = high;

        while (left < right) {
            while (arr[left] <= pivot && left <= high - 1) {
                left++;
            }
            while (arr[right] > pivot && right >= low + 1) {
                right--;
            }
            if (left < right) {
                // Swap arr[left] and arr[right]
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }

        // Swap pivot element with arr[right]
        int temp = arr[low];
        arr[low] = arr[right];
        arr[right] = temp;

        return right;
    }
}

public class QuickSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the size of the array
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();

        // Initialize the array
        int arr[] = new int[n];

        // Input array elements
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Call quickSort function
        Solution.quickSort(arr, 0, n - 1);

        // Output the sorted array
        System.out.println("Sorted array:");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();  

        sc.close();
    }
}
