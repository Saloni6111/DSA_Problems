struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
        // Base case: an empty tree is a valid BST
        if (root == nullptr) return true;

        // If there is a restriction on the minimum value
        if (minNode != nullptr && root->val <= minNode->val) return false;
        // If there is a restriction on the maximum value
        if (maxNode != nullptr && root->val >= maxNode->val) return false;

        // Recursively validate the left and right subtrees
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
/*
    2
   / \
  1   3
  Expected : True

    10
   / \
  5   15
     / \
    6   20
  Expected : False

*/
