def canFinish(numCourses, prerequisites):
    # Create a map where each course points to a list of its prerequisites
    preMap = {i : [] for i in range(numCourses)}
  
    for crs, pre in prerequisites:
        preMap[crs].append(pre)
    
    visitSet = set()
    def dfs(crs):
        # If we've encountered this course again in the current path, it means there's a cycle.
        if crs in visitSet: 
            return False
        # If there are no prerequisites for this course, we can finish this course, return True
        if preMap[crs] == []: 
            return True
        # Add this course to visitSet to track it in the current DFS path
        visitSet.add(crs)
        # Traverse the prerequisites for this course recursively and if any prerequisite leads to a cycle, return False
        for pre in preMap[crs]:
            if not dfs(pre): 
                return False
        
        # Once all prerequisites for the current course have been successfully checked, remove the course from visitSet to prevent false cycle detection while backtracking
        visitSet.remove(crs)
        # Mark this course as processed by setting its prerequisites list to empty to avoid rechecking the same course multiple times
        preMap[crs] = []
        # If we reach here, it means this course and all its prerequisites can be completed
        return True

    # We need to check every course because some courses might not be connected in a single prerequisite chain
    for crs in range(numCourses):
        if not dfs(crs):
            return False
    return True
    
if __name__ == "__main__":
    # Test Case 1
    numCourses = 2
    prerequisites = [[0, 1]]
    result = canFinish(numCourses, prerequisites)
    print(result)  # Expected output: True (You can take course 1, then course 0)

    # Test Case: 2
    numCourses = 2
    prerequisites = [[0,1],[1,0]]
    result = canFinish(numCourses,prerequisites)
    print(result)
    
    # Test Case: 3
    numCourses = 2
    prerequisites = [[1,0],[0,1]]
    result = canFinish(numCourses,prerequisites)
    print(result)
    
    # Test Case: 4
    numCourses = 2
    prerequisites = [[1,0]]
    result = canFinish(numCourses,prerequisites)
    print(result)
