// https://leetcode.com/problems/maximum-binary-tree-ii/


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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {        
        if(root == nullptr) {
            return new TreeNode(val, nullptr, nullptr);
        }
            
        if(root->val > val) {
            root->right = insertIntoMaxTree(root->right, val);
        } else {
            root = new TreeNode(val, root, nullptr);
        }
        
        return root;                        
    }
};