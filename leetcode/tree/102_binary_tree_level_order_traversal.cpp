// https://leetcode.com/problems/binary-tree-level-order-traversal/
// medium, tree, breadth-first-search, binary-tree

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        result.push_back({});
        
        queue<TreeNode*> node_queue;  
        queue<int> level_queue;
        
        node_queue.push(root);        
        level_queue.push(1);
        
        while(!node_queue.empty()) {
            TreeNode* curr_node = node_queue.front();
            int curr_level = level_queue.front();
            
            if(curr_node->left) {
                node_queue.push(curr_node->left);
                level_queue.push(curr_level + 1);
            }
            if(curr_node->right) {
                node_queue.push(curr_node->right);
                level_queue.push(curr_level + 1);
            }
            
            result.back().push_back(curr_node->val);            
            node_queue.pop();
            level_queue.pop();
            
            if(!level_queue.empty() && curr_level < level_queue.front()) {
                result.push_back({});
            }            
        }
        
        
        return result;                
    }
};