// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    // pair<subtree_min, subtree_max>
    pair<int, int> max_rec(TreeNode* root, int& max_diff) {
        if(root == nullptr) return {0, 0};        
        auto res = make_pair(root->val, root->val);        
        
        if(root->left) {
            auto left_res = max_rec(root->left, max_diff);    
            max_diff = max(max_diff, abs(root->val - left_res.first));
            max_diff = max(max_diff, abs(root->val - left_res.second));
            res.first = min(res.first, left_res.first);
            res.second = max(res.second, left_res.second);
        }

        if(root->right) {
            auto right_res = max_rec(root->right, max_diff);    
            max_diff = max(max_diff, abs(root->val - right_res.first));
            max_diff = max(max_diff, abs(root->val - right_res.second));
            res.first = min(res.first, right_res.first);
            res.second = max(res.second, right_res.second);
        }
        
        return res;                                        
    }
    
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int max_diff = INT_MIN;
        max_rec(root, max_diff);
        return max_diff;
    }
};