
import java.util.*;


class MergeSort{

    //Function to merge two sorted arrays
    static List<Integer> merge(List<Integer> left, List<Integer> right){

        //'i' is used to iterate over left list and 'j' is used to iterate over right list
        int i=0,j=0;
        int l=left.size(),r=right.size();

        //Merged array (result)
        List<Integer> res= new ArrayList<>();

        while(i<l && j<r){
            if(left.get(i)>right.get(j)){
                res.add(right.get(j));
                j++;
            }
            else{
                res.add(left.get(i));
                i++;
            }
        }  

        //Adding remaining elements of left array at the end of result 
        while(i<l){
            res.add(left.get(i));
            i++;
        }

        //Adding remaining elements of right array at the end of result
        while (j<r) { 
            res.add(right.get(j));
            j++;
        }
        return res;

    }

    // Function to implement MergeSort Algorithm
    static List<Integer> mergeSort(List<Integer> arr){
        int n = arr.size();

        if(n==1){
            return arr;
        }

        //Splitting given array into two halves and recursively calling mergeSort to sort them
        List<Integer> left= mergeSort(arr.subList(0, n/2));   
        List<Integer> right= mergeSort(arr.subList(n/2, n));

        return merge(left,right);
    }
    public static void main(String args[]){

        //Example Test Case: arr=[3,4,1,7,9,2,8,6,5]
        //Desired Output: [1,2,3,4,5,6,7,8,9]

        //Populating input array values
        List<Integer> arr=new ArrayList<>();
        arr.add(3);
        arr.add(4);
        arr.add(1);
        arr.add(7);
        arr.add(9);
        arr.add(2);
        arr.add(8);
        arr.add(6);
        arr.add(5);

        System.out.println("Sorted Array:\n"+mergeSort(arr));

    }
}
    
