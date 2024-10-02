def trap(height):
    # Edge case: if the input array is empty, return 0
    if not height:
        return 0

    # Initialize two pointers
    left, right = 0, len(height) - 1
    # Initialize variables to store the maximum heights on both sides
    left_max, right_max = height[left], height[right]
    # Initialize a variable to store the total water trapped
    water_trapped = 0

    # Loop until the two pointers meet
    while left < right:
        # If the left_max is less than the right_max, move the left pointer inward
        if left_max < right_max:
            left += 1
            # Update the left_max value
            left_max = max(left_max, height[left])
            # Calculate the water trapped at the current position and add it to the total
            water_trapped += left_max - height[left]
        # If the right_max is less than or equal to the left_max, move the right pointer inward
        else:
            right -= 1
            # Update the right_max value
            right_max = max(right_max, height[right])
            # Calculate the water trapped at the current position and add it to the total
            water_trapped += right_max - height[right]

    # Return the total water trapped
    return water_trapped

# Test Cases
print(trap([4, 2, 0, 3, 2, 5]))  # Output: 9
print(trap([1, 0, 2]))           # Output: 1
