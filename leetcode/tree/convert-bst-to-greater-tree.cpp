// https://leetcode.com/problems/convert-bst-to-greater-tree/
// medium, tree, depth-first-search, binary-search-tree, binary-tree


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
    int convert_rec(TreeNode* root, int curr_sum) {
        if(root == nullptr) return 0;
        
        if(root->right) {
            root->val = root->val + convert_rec(root->right, curr_sum);            
        } else {
            root->val = root->val + curr_sum;
        }
        
        if(root->left) {
            return convert_rec(root->left, root->val);
        }        
        
        return root->val;                
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        convert_rec(root, 0);
        return root;
    }
};