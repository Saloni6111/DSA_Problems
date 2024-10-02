/*How to find duplicate elements in a given integers list in java using Stream functions?

Input 1 :
arr[] = [10,15,8,49,25,98,98,32,15]
Output : 98, 15

Input 2 :
arr[] = [1, 1, 85, 6, 2, 3, 65, 6, 45, 45, 5662, 2582, 2, 266, 666, 656]
Output : 1 6 2 45 */


import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class FindDuplicates {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//int arr[] = {10,15,8,49,25,98,98,32,15};
		int arr[] = {1, 1, 85, 6, 2, 3, 65, 6, 45, 45, 5662, 2582, 2, 266, 666, 656};
		Set<Integer> set = new HashSet<>();
		Arrays.stream(arr).filter(n -> !set.add(n)).forEach(n -> System.out.print(n + " "));


	}

}
