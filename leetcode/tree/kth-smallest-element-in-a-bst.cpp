// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    
    int kth_rec(TreeNode* root, int k, int&c) {
        if(root->left) {
            auto res = kth_rec(root->left, k, c);
            if(res != -1) return res;
        }
                
        ++c;        
        if(k == c) return root->val;
        
        if(root->right) {
            auto res = kth_rec(root->right, k, c);
            if(res != -1) return res;
        }
        
        return -1;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        
        int c = 0;
        return kth_rec(root, k, c);                    
    }
};