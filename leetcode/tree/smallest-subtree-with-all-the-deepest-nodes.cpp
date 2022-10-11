// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
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
    
    pair<TreeNode*, int> sub_rec(TreeNode* root, int curr_level) {
        if(root == nullptr) return { nullptr, 0 };
        
        if(root->left == nullptr && root->right == nullptr) return {root, curr_level};
        
        auto left_res = sub_rec(root->left, curr_level + 1);
        auto right_res = sub_rec(root->right, curr_level + 1);

        if(left_res.second > right_res.second) return left_res;
        else if(left_res.second < right_res.second) return right_res;
        
        return {root, left_res.second};                                        
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {        
        return sub_rec(root, 0).first;        
    }
};