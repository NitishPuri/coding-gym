// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
// medium, hash-table, tree, depth-first-search, breadth-first-search, binary-tree

#include <utility>

using namespace std;

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
    pair<TreeNode*, int> lca_rec(TreeNode* root) {
        if(root == nullptr) return {nullptr, 0};
        
        auto left_res = lca_rec(root->left);
        auto right_res = lca_rec(root->right);
        
        if(left_res.second > right_res.second) return {left_res.first, left_res.second + 1};
        if(right_res.second > left_res.second) return {right_res.first, right_res.second + 1};
        
        return {root, left_res.second + 1};                
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca_rec(root).first;
    }
};