class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def morris_preorder_traversal(root):
    result = []
    current = root

    while current:
        if current.left is None:
            result.append(current.val)
            current = current.right
        else:
            predecessor = current.left
            while predecessor.right and predecessor.right != current:
                predecessor = predecessor.right
            
            if predecessor.right is None:
                result.append(current.val)  # Add value before making a thread
                predecessor.right = current
                current = current.left
            else:
                predecessor.right = None
                current = current.right

    return result
