// https://leetcode.com/problems/longest-univalue-path/

#include <iostream>

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
    int longest_rec(TreeNode* root,int& curr_max) {
        if(root == nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr) return 1;
                
        int res = 1;
        int left_res = longest_rec(root->left, curr_max);
        if(root->left && root->val == root->left->val) {
            res = max(res, left_res + 1);
        }
        
        int right_res = longest_rec(root->right, curr_max);
        if(root->right && root->val == root->right->val) {
            if(res > 1) {
                curr_max = max(curr_max, left_res + right_res + 1);
            }
            res = max(res, right_res + 1);
        }
                
        curr_max = max(curr_max, res);
        
        return res;        
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        int curr_max = 1;
        longest_rec(root, curr_max);        
        return curr_max - 1;
    }
};