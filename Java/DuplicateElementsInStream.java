// Java program to find the duplicate 
// elements in a Stream using Set 

import java.util.*; 
import java.util.stream.*; 

public class DuplicateElement { 

	// Function to find the 
	// duplicates in a Stream 
	public static <T> Set<T> 
	findDuplicateInStream(Stream<T> stream) 
	{ 

		// Set to store the duplicate elements 
		Set<T> items = new HashSet<>(); 

		// Return the set of duplicate elements 
		return stream 

			// Set.add() returns false 
		
			.filter(n -> !items.add(n)) 

		
			.collect(Collectors.toSet()); 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 

		// Initial stream 
		Stream<Integer> stream 
			= Stream.of(5, 13, 4, 
						21, 13, 27, 
						2, 59, 59, 34); 

		
		System.out.println( 
			findDuplicateInStream(stream)); 
	} 
} 
