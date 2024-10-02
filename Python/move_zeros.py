def move_zeroes(nums):
    """I have used two-pointer approach"""
    last_non_zero = 0

    # Move all the non-zero elements forward
    for current in range(len(nums)):
        if nums[current] != 0:
            nums[last_non_zero] = nums[current]
            last_non_zero += 1

    # Fill the remaining elements with 0s
    for i in range(last_non_zero, len(nums)):
        nums[i] = 0

# Example
input_array = [0, 1, 0, 3, 12]
move_zeroes(input_array)
print(input_array)