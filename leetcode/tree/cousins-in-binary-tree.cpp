// https://leetcode.com/problems/cousins-in-binary-tree/


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
    void isCousins_rec(TreeNode* root, int x, int y, int d, int& d_x, int& d_y) {
        
        if(root == nullptr) return;
        
        if(root->val == x) {
            d_x = d;
            return;
        }
        if(root->val == y) {
            d_y = d;
            return;
        }
        
        if(d_x != -1 && d >= d_x) return;
        if(d_y != -1 && d >= d_y) return;
        
        if(d_x != -1 && d_y != -1) {
            return;
        }
        
        if(root->left && root->right) {
            if(root->left->val == x && root->right->val == y) return;
            if(root->left->val == y && root->right->val == x) return;
        }
                
        
        isCousins_rec(root->left, x, y, d + 1, d_x, d_y);
        isCousins_rec(root->right, x, y, d + 1, d_x, d_y);
                
        
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int d_x = -1, d_y = -1;
        isCousins_rec(root, x, y, 0, d_x, d_y);
        return(d_x == d_y && d_x != -1);
    }
};