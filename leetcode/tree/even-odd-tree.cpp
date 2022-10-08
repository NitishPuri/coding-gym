// https://leetcode.com/problems/even-odd-tree/


#include <queue>

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
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        int curr_level = 0;
        while(!q.empty()) {         
            int size = q.size(), prev = 0;            
            for(int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                
                // Check odd/even                 
                if(curr_level & 1)  {
                    if(node->val & 1) return false;
                } else {
                    if(!(node->val & 1)) return false;
                }
                
                // Check increasing/decreasing
                if(i == 0) {
                    prev = node->val;
                } else {
                    if(curr_level & 1) {
                        if(node->val >= prev) return false;
                        prev = node->val;
                    } else {
                        if(node->val <= prev) return false;
                        prev = node->val;
                    }
                }
                              
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);                
            }            
            ++curr_level;            
        }
        
        return true;
        
    }
};