// Java program for implementation of QuickSort
class QuickSort
{
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high]; 
        int i = (low-1); // index of smaller element
        for (int j=low; j&lt;high; j++)
        {
          
            if (arr[j] &lt;= pivot)
            {
                i++;

                // swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

  
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }



    void sort(int arr[], int low, int high)
    {
        if (low &lt; high)
        {
          
            int pi = partition(arr, low, high);

        
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }

    /* A utility function to print array of size n */
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i&lt;n; ++i)
            System.out.print(arr[i]+&quot; &quot;);
        System.out.println();
    }

    // Driver program
    public static void main(String args[])
    {
        int arr[] = {10, 7, 8, 9, 1, 5};
        int n = arr.length;

        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n-1);

        System.out.println(&quot;sorted array&quot;);
        printArray(arr);
    }
}

