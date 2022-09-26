// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};  
        
        vector<int> result;
        
        stack<TreeNode*> node_stack;
        stack<int> state_stack;
        
        node_stack.push(root); 
        state_stack.push(2);
        
        while(!node_stack.empty()) {
            TreeNode* curr = node_stack.top();
            int state = state_stack.top()--;
            switch(state) {
                case 2: // visit left child.
                    if(curr->left) {
                        node_stack.push(curr->left); 
                        state_stack.push(2);
                    }
                    break;
                case 1: // visit self.
                    result.push_back(curr->val);                    
                    break;
                case 0: // visit right child.
                    if(curr->right) {
                        node_stack.push(curr->right);
                        state_stack.push(2);
                    }
                    break;
                case -1: // remove self from stack.
                    node_stack.pop();
                    state_stack.pop();
            }                        
        }
        
        return result;                
    }

/* Recursive        
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};       


        vector<int> result;
        inorder(root, result);        
        return result;                
    }

    void inorder(TreeNode* root, vector<int>& result) {
        if(!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
*/
};