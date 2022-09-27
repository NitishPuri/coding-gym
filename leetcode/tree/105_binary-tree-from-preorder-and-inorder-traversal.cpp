// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    using vitr = vector<int>::iterator;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_rec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode* buildTree_rec(vitr pre_begin, vitr pre_end,
                            vitr in_begin, vitr in_end) 
    {
        if(pre_begin == pre_end) return nullptr;
        
        TreeNode* root = new TreeNode(*pre_begin);
        
        auto root_itr = std::find(in_begin, in_end, root->val);
        auto left_size = std::distance(in_begin, root_itr);
        
        root->left = buildTree_rec(pre_begin+1, pre_begin + 1 + left_size,
                                  in_begin, root_itr);
        root->right = buildTree_rec(pre_begin + 1 + left_size, pre_end,
                                   root_itr + 1, in_end);
                                    
        return root;                
    }
};