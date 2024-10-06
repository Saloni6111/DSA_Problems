def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2 
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1 

arr = list(map(int, input("Enter a sorted list of numbers separated by spaces: ").split()))
target = int(input("Enter the target number: "))

result = binary_search(arr, target)
print(f"Element found at index: {result}" if result != -1 else "Element not found")
