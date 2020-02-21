// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == nullptr)
            return result;
        
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        
        while(!node_stack.empty()) {
            TreeNode* curr = node_stack.top();
            node_stack.pop();
            
            if(curr->right)
                node_stack.push(curr->right);            
            
            if(curr->left)
                node_stack.push(curr->left);
            
            result.push_back(curr->val);
        }
        
        return result;

/* Recursive        
        vector<int> result;
        if(root == nullptr) 
            return result;
        result.push_back(root->val);
        
        auto left_result = preorderTraversal(root->left);
        result.insert(result.end(), left_result.begin(), left_result.end());
        
        auto right_result = preorderTraversal(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());        
        
        return result;
*/
    }
    
    vector<int> preorderTraversal_recursive(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) 
            return result;
        result.push_back(root->val);
        
        auto left_result = preorderTraversal_recursive(root->left);
        result.insert(result.end(), left_result.begin(), left_result.end());
        
        auto right_result = preorderTraversal_recursive(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());        
        
        return result;
    }
};