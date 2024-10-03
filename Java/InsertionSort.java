/*INSERTION SORT-->
-> Insertion sort is a simple sorting algorithm that works by building a sorted array one element at a time.
It is considered an ” in-place ” sorting algorithm, meaning it doesn’t require any additional memory space beyond the original array.

-> The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked
and placed at the correct position in the sorted part.
  
* ALGORITHM -->
1) Input :- An array of integers.

2) We will take an outer loop, which iterate from zeroth index of an array to (length of array - 1)th index.
    :)This loop select an element in each iteration from the unsorted array.
    :)The first element of the array is assumed to be sorted.

3) For each element, compare it with the elements before it(or compare it with sorted sub-array) by using inner loop.
    :)Shift all the elements in sorted sub-array that is greater than the value to be sorted using swapping function inside inner loop.
    :)Insert current element into it's correct position.

4) Output -> Sorted array in ascending order.

Time complexity -> Best Case=O(n):when the array is already sorted.
Average and Worst Case = O(n^2):due nested loops
*/

class InsertionSort{
    static void insertionSort(int[] arr,int n){
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                j--;
            }
        }

    }public static void main(String [] args){
        int[] arr={7,9,24,27,2,15};
        int n=arr.length;
        insertionSort(arr,n);
        System.out.println("After insertion sort");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");

        }
    }
}