import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

public class BinaryTreeVerticalOrder {
    class NodeColumnPair {
        TreeNode node;
        int column;
        
        NodeColumnPair(TreeNode node, int column) {
            this.node = node;
            this.column = column;
        }
    }
    
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        Map<Integer, List<Integer>> columnMap = new HashMap<>();
        Queue<NodeColumnPair> queue = new LinkedList<>();
        int minColumn = 0, maxColumn = 0;
        queue.offer(new NodeColumnPair(root, 0));
        
        while (!queue.isEmpty()) {
            NodeColumnPair pair = queue.poll();
            TreeNode node = pair.node;
            int column = pair.column;
            
            columnMap.putIfAbsent(column, new ArrayList<>());
            columnMap.get(column).add(node.val);
       
            minColumn = Math.min(minColumn, column);
            maxColumn = Math.max(maxColumn, column);
            
          
            if (node.left != null) {
                queue.offer(new NodeColumnPair(node.left, column - 1));
            }
            
            if (node.right != null) {
                queue.offer(new NodeColumnPair(node.right, column + 1));
            }
        }
        
       
        for (int i = minColumn; i <= maxColumn; i++) {
            result.add(columnMap.get(i));
        }
        
        return result;
    }

    public static void main(String[] args) {
        BinaryTreeVerticalOrder solution = new BinaryTreeVerticalOrder();
        
        
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        
       
        List<List<Integer>> verticalOrderTraversal = solution.verticalOrder(root);
        
        
        for (List<Integer> column : verticalOrderTraversal) {
            System.out.println(column);
        }
    }
}
