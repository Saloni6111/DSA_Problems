def merge_sort(arr):
    # Base case: If the array has one or zero elements, it's already sorted
    if len(arr) > 1:
        # Find the middle index
        mid = len(arr) // 2
        
        # Divide the array into two halves
        left_half = arr[:mid]
        right_half = arr[mid:]
        
        # Recursively sort the two halves
        merge_sort(left_half)
        merge_sort(right_half)
        
        # Initialize pointers for left_half (i), right_half (j), and main array (k)
        i = j = k = 0
        
        # Merge the two halves back into the main array
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        
        # If there are any remaining elements in left_half, add them
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        
        # If there are any remaining elements in right_half, add them
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1


user_input = input("Enter numbers separated by spaces: ")
arr = list(map(int, user_input.split()))  # Convert input string to list of integers

print("Original array:", arr)
merge_sort(arr)  # Perform merge sort
print("Sorted array:", arr)  # Output the sorted array
