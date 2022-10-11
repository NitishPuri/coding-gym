// https://leetcode.com/problems/house-robber-iii/
// medium, dynamic-programming, tree, depth-first-search, binary-tree


#include <vector>
#include <queue>

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
    
    // pair<include root, dont include root>     
    pair<int, int> find_sum(TreeNode* root) {
        if(root == nullptr) return {0, 0};
        
        if(root->left == nullptr && root->right == nullptr) return {root->val, 0};
        
        auto left_res = find_sum(root->left);
        auto right_res = find_sum(root->right);
        
        int include_root = root->val + left_res.second + right_res.second;
        int dont_include_root = max(left_res.first, left_res.second) + max(right_res.first, right_res.second);
        
        return {include_root, dont_include_root};                                                
    }
    
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;        
        auto res = find_sum(root);
        return max(res.first, res.second);        
    }
};

TreeNode* buildTree1() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution s;
    s.rob(buildTree1());
    return 0;
}
