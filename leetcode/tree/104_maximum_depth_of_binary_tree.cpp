// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max( maxDepth(root->left), maxDepth(root->right) );
    }    
};