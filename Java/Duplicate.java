//Given an array of integers containing n + 1 integers where each integer is in the range [1, n] inclusive, find the duplicate number.
import java.util.*;

public class Duplicate {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of array");
        int n=sc.nextInt();
        int arr[]=new int[n+1];
        System.out.println("Enter elements in the array");
        for(int i=0;i<=n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Duplicate element is :"+findDuplicate(arr, n));

    }
    public static int findDuplicate(int arr[],int n){
        int res=0;
        for(int i=1;i<=n;i++){
             res^=i;
        }
        for(int x:arr){
            res^=x;
        }
        return res;
    }
}
