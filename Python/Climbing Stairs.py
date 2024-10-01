def climb_stairs(n):
    # Function to print all paths
    def find_paths(steps_left, path):
        # Base case: If no steps are left, we have a valid path
        if steps_left == 0:
            all_paths.append(path)
            return
        # Recursive case: Try taking 1 step
        if steps_left >= 1:
            find_paths(steps_left - 1, path + [1])
        # Recursive case: Try taking 2 steps
        if steps_left >= 2:
            find_paths(steps_left - 2, path + [2])

    # List to store all possible paths
    all_paths = []
    # Call the function to find all paths
    find_paths(n, [])

    return all_paths

# Input from the user
n = int(input("Enter the number of steps: "))

# Get all the possible ways to climb the stairs
paths = climb_stairs(n)

# Print the total number of ways and each distinct path
print(f"Total number of distinct ways to climb {n} steps: {len(paths)}")
print("The possible step sequences are:")
for path in paths:
    print(path)
