// https://leetcode.com/problems/add-one-row-to-tree/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {        
        if(root == nullptr) return nullptr;
        
        if(depth == 1) return new TreeNode(val, root, nullptr);

        if(depth == 2) {                        
            root->left = new TreeNode(val, root->left, nullptr); 
            root->right = new TreeNode(val, nullptr, root->right);
        } else {
            addOneRow(root->left, val, depth - 1);
            addOneRow(root->right, val, depth - 1);
        }                
        return root;        
    }
};