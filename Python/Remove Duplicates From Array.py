def remove_duplicates(arr):
    # create a list to store the unique elements 
    unique = []
    # create a set called seen to track elements we've already encountered
    seen = set()

# Finally, we return the unique list.
# We iterate through each element num in the array arr.
    for num in arr:
        # If num is not already in seen, it's a unique element
        # add it to unique and also add it to seen.
        if num not in seen:
            unique.append(num)
            seen.add(num)

    return unique


if __name__ == "__main__":
    # Test Case 1: Regular case with duplicates
    arr1 = [1, 2, 2, 3, 4, 4]
    result1 = remove_duplicates(arr1)
    assert result1 == [1, 2, 3, 4], f"Test Case 1 Failed: {result1}"

    # Test Case 2: No duplicates
    arr2 = [1, 2, 3, 4]
    result2 = remove_duplicates(arr2)
    assert result2 == [1, 2, 3, 4], f"Test Case 2 Failed: {result2}"

    # Test Case 3: Empty array
    arr3 = []
    result3 = remove_duplicates(arr3)
    assert result3 == [], f"Test Case 3 Failed: {result3}"

    # Test Case 4: All elements are duplicates
    arr4 = [1, 1, 1, 1]
    result4 = remove_duplicates(arr4)
    assert result4 == [1], f"Test Case 4 Failed: {result4}"

    # Test Case 5: Single element array
    arr5 = [5]
    result5 = remove_duplicates(arr5)
    assert result5 == [5], f"Test Case 5 Failed: {result5}"

    # Test Case 6: Array with negative and positive numbers
    arr6 = [-2, -1, 0, 1, 2, 2, 3, 3]
    result6 = remove_duplicates(arr6)
    assert result6 == [-2, -1, 0, 1, 2, 3], f"Test Case 6 Failed: {result6}"

    # Test Case 7: Array with duplicates at the start and end
    arr7 = [4, 4, 5, 6, 7, 7, 7]
    result7 = remove_duplicates(arr7)
    assert result7 == [4, 5, 6, 7], f"Test Case 7 Failed: {result7}"

    # Test Case 8: Large array with many duplicates
    arr8 = [1] * 1000 + [2] * 1000 + [3] * 1000
    result8 = remove_duplicates(arr8)
    assert result8 == [1, 2, 3], f"Test Case 8 Failed: {result8}"

    print("All test cases passed!")
