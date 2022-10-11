// https://leetcode.com/problems/binary-tree-postorder-traversal/
// easy, stack, tree, depth-first-search, binary-tree

#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
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
                case 1:  // visit right child.
                    if(curr->right) {
                        node_stack.push(curr->right);
                        state_stack.push(2);
                    }
                    break;
                case 0: // visit self.
                    result.push_back(curr->val);
                    node_stack.pop();
                    state_stack.pop();  
                    break;
            }
        }
        
        return result;
        
        // postorder(root, result);
        // return result;        
    }
    
    void postorder(TreeNode* root, vector<int>& result) {
        if(!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};