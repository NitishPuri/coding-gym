// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// medium, tree, depth-first-search, breadth-first-search, binary-tree

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
    vector<int> largestValues(TreeNode* root) {
        
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;
        
        while(!q.empty()) {
            
            int size = q.size();
            int ans = INT_MIN;
            for(int i = 0; i < size; i++) {                
                auto front = q.front(); q.pop();    
                ans = max(ans, front->val);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);                                                                                                   
            }
            
            res.push_back(ans);
        }
        
        return res;
        
        
    }
};