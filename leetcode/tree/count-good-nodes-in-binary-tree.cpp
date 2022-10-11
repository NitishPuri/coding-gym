// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// medium, tree, depth-first-search, breadth-first-search, binary-tree

#include <iostream>

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
    int good_rec(TreeNode* root, int curr_max) {
        if(root == nullptr) return 0;
        
        if(root->val >= curr_max) {
            return 1 + good_rec(root->left, root->val) + good_rec(root->right, root->val);
        }
                
        return good_rec(root->left, curr_max) + good_rec(root->right, curr_max);
        
    }
public:
    int goodNodes(TreeNode* root) {
        return good_rec(root, INT_MIN);                
    }
};