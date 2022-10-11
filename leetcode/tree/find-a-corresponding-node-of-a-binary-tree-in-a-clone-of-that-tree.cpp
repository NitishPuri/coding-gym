// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// easy, tree, depth-first-search, breadth-first-search, binary-tree

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original, cloned});
        
        while(!q.empty()) {
            auto o = q.front().first; 
            auto c = q.front().second;
            
            if(o->val == target->val) { return c; }
            
            if(o->left) q.push({o->left, c->left});
            if(o->right) q.push({o->right, c->right});
            
            q.pop();            
        }
        
        return nullptr;
        
    }
};