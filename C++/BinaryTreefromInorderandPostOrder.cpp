                            
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to build a binary tree
    // from inorder and postorder traversals
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }

        // Create a map to store the indices
        // of elements in the inorder traversal
        map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }

        // Call the recursive function
        // to build the binary tree
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
            postorder.size() - 1, hm);
    }

    // Recursive function to build a binary
    // tree from inorder and postorder traversals
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie,
        vector<int>& postorder, int ps, int pe, map<int, int>& hm) {

        // Base case: If the subtree
        // is empty, return NULL
        if (ps > pe || is > ie) {
            return NULL;
        }

        // Create a new TreeNode
        // with the root value from postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find the index of the root
        // value in inorder traversal
        int inRoot = hm[postorder[pe]];
        
        // Number of nodes in the left subtree
        int numsLeft = inRoot - is; 

        // Recursively build the
        // left and right subtrees
        root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder,
            ps, ps + numsLeft - 1, hm);

        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder,
            ps + numsLeft, pe - 1, hm);

        // Return the root of
        // the constructed subtree
        return root;
    }
};

// Function to print the
// inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print the given vector
void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example input vectors
    vector<int> inorder;
    vector<int> postorder;
    cout<<"Enter Number of elements in Inorder and Preorder: "<<endl;
    int n; cin>>n;
    cout<<"Enter Inorder: "<<endl;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        inorder.push_back(x);
    }
    cout<<"Enter Postorder: "<<endl;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        postorder.push_back(x);
    }
    // Display the input vectors
    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Postorder Vector: ";
    printVector(postorder);

    Solution sol;

    // Build the binary tree and
    // print its inorder traversal
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}

                            
                        