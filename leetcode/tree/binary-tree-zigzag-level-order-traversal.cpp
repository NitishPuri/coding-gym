// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// tree, breadth-first-search, binary-tree, medium


#include <queue>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};        
        vector<vector<int>> res;        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            res.push_back({});
            for(int i = 0; i < size; ++i) {
                auto front = q.front(); q.pop();
                res.back().push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);                                
            }
            if( (res.size() & 1) == 0) {  // even level
                reverse(res.back().begin(), res.back().end());
            }
        }
        
        return res;
    }
};