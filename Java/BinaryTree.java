import java.util.LinkedList;
import java.util.Queue;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode() {}
    
    TreeNode(int val) {
        this.val = val;
    }
    
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class BinaryTree {

    // Method to find the maximum depth of the binary tree using BFS (iterative approach)
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int depth = 0;
        
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            depth++;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode currentNode = queue.poll();
                
                if (currentNode.left != null) {
                    queue.offer(currentNode.left);
                }
                
                if (currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }
        }
        
        return depth;
    }
    
    // Main method to test the code
    public static void main(String[] args) {
        // Example binary tree: [3,9,20,null,null,15,7]
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
        
        BinaryTree tree = new BinaryTree();
        int maxDepth = tree.maxDepth(root);
        
        System.out.println("The maximum depth of the tree is: " + maxDepth);
        
        // Test with an empty tree
        TreeNode emptyTree = null;
        int emptyTreeDepth = tree.maxDepth(emptyTree);
        System.out.println("The maximum depth of an empty tree is: " + emptyTreeDepth);
    }
}
