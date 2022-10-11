// https://leetcode.com/problems/diameter-of-binary-tree/
// easy, tree, depth-first-search, binary-tree

#include <vector>

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
    pair<int, int> dia_rec(TreeNode* root) {
        if(root == nullptr) return {-1, -1};
        
        auto left = dia_rec(root->left);
        auto right = dia_rec(root->right);
        
        int max_dia = max(left.first, right.first);
        max_dia = max(max_dia, left.second + 1 + right.second + 1);
        int max_depth = max(left.second + 1, right.second + 1);
        
        return {max_dia, max_depth};                
    }
    
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dia_rec(root).first;                        
    }
};