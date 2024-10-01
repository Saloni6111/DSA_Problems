def longestIncreasingPath(matrix):
    ROWS, COLS = len(matrix), len(matrix[0])
    # Dictionary to store the length of the longest increasing path from each cell (r, c)
    dp = {}  

    # dfs helper function
    # r, c: current row and column
    # prevVal: the value of the previous cell in the path to ensure  increasing order
    def dfs(r, c, prevVal):
        # Base case: check if we are out of bounds or if the current cell's value is not greater than the previous cell's value
        if (r < 0 or r == ROWS or c < 0 or c == COLS or matrix[r][c] <= prevVal):
            return 0  
        # If the result for this cell is already computed, return it from dp (memoization)
        if (r, c) in dp:
            return dp[(r, c)]
            
        # Start with length 1 for the current cell, as every cell is a path of at least length 1
        res = 1
        # Explore all four directions (down, up, right, left) and recursively call dfs
        # Add 1 to the result of dfs for each valid direction to extend the path
        res = max(res, 1 + dfs(r + 1, c, matrix[r][c]))  # Move down
        res = max(res, 1 + dfs(r - 1, c, matrix[r][c]))  # Move up
        res = max(res, 1 + dfs(r, c + 1, matrix[r][c]))  # Move right
        res = max(res, 1 + dfs(r, c - 1, matrix[r][c]))  # Move left 
        # Store the computed result in dp for the current cell to avoid redundant calculations
        dp[(r, c)] = res
        return res  

    for r in range(ROWS):
        for c in range(COLS):
            # Start DFS from cell (r, c) with an initial previous value of -1 to ensure any value in the matrix can be used
            dfs(r, c, -1)
    # The result is the maximum value among all computed LIPs
    return max(dp.values())

if __name__ == "__main__":
    # Test Case 1
    matrix = [[9,9,4],[6,6,8],[2,1,1]] 
    result = longestIncreasingPath(matrix)
    print(result) # Expected output: 4
    
    # Test Case 2
    matrix = [[3,4,5],[3,2,6],[2,2,1]]
    result = longestIncreasingPath(matrix)
    print(result) # Expected output: 4
    
    # Test Case 3
    matrix = [[1]]
    result = longestIncreasingPath(matrix)
    print(result) # Expected output: 1
    
    # Test Case 4
    matrix = [[1,2,3],[2,1,4],[7,6,5]]
    result = longestIncreasingPath(matrix)
    print(result) # Expected output: 7
    
    # Test Case 5
    matrix = [[5,5,3],[2,3,6],[1,1,1]]
    result = longestIncreasingPath(matrix)
    print(result) # Expected output: 4
