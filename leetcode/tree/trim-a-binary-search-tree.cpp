// https://leetcode.com/problems/trim-a-binary-search-tree/
// medium, tree, depth-first-search, binary-search-tree, binary-tree


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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
                
        if(root->val < low) {
            // remove lower
            root->right = trimBST(root->right, low, high);
            return root->right;
        } else if(root->val <= high) {
            // keep
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        } else {
            // remove higher
            root->left = trimBST(root->left, low, high);
            return root->left;
        }
                        
        return root;
                                        
    }
};