// https://leetcode.com/problems/symmetric-tree/
// easy, tree, depth-first-search, breadth-first-search, binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;        
        // return isMirror(root->left, root->right); 
        return isMirror_itr(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;        
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    
    bool isMirror_itr(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;        
        if(left == nullptr || right == nullptr) return false;
        
        stack<TreeNode*> left_stack, right_stack;
        left_stack.push(left);
        right_stack.push(right);
        
        while(!left_stack.empty()) {
            TreeNode* curr_left = left_stack.top();
            TreeNode* curr_right = right_stack.top();
            if(curr_left->val != curr_right->val) return false;
            left_stack.pop();
            right_stack.pop();
            
            if(curr_left->left != nullptr || curr_right->right != nullptr) {
                if(curr_left->left == nullptr || curr_right->right == nullptr) return false;
                left_stack.push(curr_left->left);
                right_stack.push(curr_right->right);
            }
            
            if(curr_left->right != nullptr || curr_right->left != nullptr) {
                if(curr_left->right == nullptr || curr_right->left == nullptr) return false;
                left_stack.push(curr_left->right);
                right_stack.push(curr_right->left);
            }                                                
        }
        return true;
    }
};