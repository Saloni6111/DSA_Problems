/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        int res = 0; // tc: O(n), sc: O(n)
        dfs(root, res);
        return res;
    }
    int dfs(Node* root, int& res) {
        if(!root) return 0;
        int first = 0, second = 0;
        for(auto& child:root->children) {
            int tmp = dfs(child, res);
            if(tmp >= first) {
                second = first;
                first = tmp;
            }
            else if(tmp >= second) second = tmp;
        }
        res = max(res, first + second);
        return max(first, second) + 1;
    }
};