// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// medium, array, hash-table, divide-and-conquer, tree, binary-tree

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    using vitr =  vector<int>::iterator;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return buildTree_rec(inorder.begin(), inorder.end(),
                            postorder.begin(), postorder.end());
    }
    
    TreeNode* buildTree_rec(vitr inorder_begin, vitr inorder_end,
                            vitr postorder_begin,vitr postorder_end) 
    {
        if(postorder_begin == postorder_end) return nullptr;
        
        auto post_root_itr = postorder_end - 1;        
        TreeNode* root = new TreeNode(*post_root_itr);
        
        auto root_itr = std::find(inorder_begin, inorder_end, root->val);
        auto left_size = std::distance(inorder_begin, root_itr);
        
        root->left = buildTree_rec(inorder_begin, root_itr,
                                   postorder_begin,
                                   postorder_begin + left_size);
        
        root->right = buildTree_rec(root_itr + 1, inorder_end,
                                    postorder_begin + left_size,
                                    post_root_itr);                                
        
        return root;
    }
        
};