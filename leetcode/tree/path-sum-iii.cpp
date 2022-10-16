// https://leetcode.com/problems/path-sum-iii/
// tree, medium, depth-first-search, binary-tree

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
    vector<long long> dfs(TreeNode* root, int targetSum, int& count) {
        if(root == nullptr) return {};        
        auto left_op = dfs(root->left, targetSum, count);
        auto right_op = dfs(root->right, targetSum, count);        
        vector<long long> res;
        res.push_back(root->val);
        if(root->val == targetSum) ++count;
        for(int i = 0; i < left_op.size(); ++i) {            
            if(root->val + left_op[i] == targetSum) ++count;
            res.push_back(root->val + left_op[i]);
        }
        for(int i = 0; i < right_op.size(); ++i) {            
            if(root->val + right_op[i] == targetSum) ++count;
            res.push_back(root->val + right_op[i]);
        }        
        return res;                
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfs(root, targetSum, count);
        return count;
    }
};