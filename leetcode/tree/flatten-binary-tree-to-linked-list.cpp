// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
    TreeNode* flatten_rec(TreeNode* root) {
        if(root == nullptr) return nullptr;
        
        auto left = root->left;
        auto right = root->right;
        
        root->left = nullptr;
        
        auto left_tail = root;
        if(left) {
            left_tail = flatten_rec(left);
            root->right = left;
        }
            
        auto right_tail = left_tail;
        if(right) {
            right_tail = flatten_rec(right);
            left_tail->right = right;
        }
        
        return right_tail;
    }
    
public:
    void flatten(TreeNode* root) {
        flatten_rec(root);                
    }
};