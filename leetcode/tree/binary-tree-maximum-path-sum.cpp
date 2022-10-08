// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max_rec(TreeNode* root, int& ans) {
        if(root == nullptr) return -10000;
        
        if(root->left == nullptr && root->right == nullptr) {
            ans = max(ans, root->val);
            return root->val;
        }
        
        auto left = max_rec(root->left, ans);
        auto right = max_rec(root->right, ans);
        
        auto ret = root->val;
        ret = max(ret, left + root->val);
        ret = max(ret, right + root->val);
                
        ans = max(ans, ret);
        ans = max(ans, left + right + root->val);
        return ret;        
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        max_rec(root, ans);
        return ans;
    }
};