// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// medium, tree, depth-first-search, binary-tree


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
    
    TreeNode* suff_rec(TreeNode* root, int limit, int curr_sum) {
        if(root == nullptr) return nullptr;
        
        if(root->left == nullptr && root->right == nullptr) {
            return (curr_sum + root->val < limit ? nullptr : root);
        }
        
        root->left = suff_rec(root->left, limit, curr_sum + root->val);
        root->right = suff_rec(root->right, limit, curr_sum + root->val);
        
        if(root->left == nullptr && root->right == nullptr) return nullptr;
        
        return root;            
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return suff_rec(root, limit, 0);                
    }
};