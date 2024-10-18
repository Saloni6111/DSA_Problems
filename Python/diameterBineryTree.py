#Function to find the diameter of the   given   binary tree.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # Initialize the diameter
        self.diameter = 0
        
        def depth(node: TreeNode) -> int:
            # If the node is None, return 0 (base case for leaf nodes)
            if not node:
                return 0
            
            # Recursively find the depth of the left and right subtree
            left_depth = depth(node.left)
            right_depth = depth(node.right)
            
            # The diameter at this node is the sum of the left depth and right depth
            self.diameter = max(self.diameter, left_depth + right_depth)
            
            # Return the height of the current node
            return max(left_depth, right_depth) + 1
        
        # Start the depth-first search from the root
        depth(root)
        
        return self.diameter
