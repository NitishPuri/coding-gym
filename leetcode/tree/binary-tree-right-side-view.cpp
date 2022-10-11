// https://leetcode.com/problems/binary-tree-right-side-view/
// medium, tree, depth-first-search, breadth-first-search, binary-tree

#include <vector>
#include <map>

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
    void dfs(TreeNode* root, map<int, int>& m, int curr_level) {
        if(root == nullptr) return;
        
        if(m.find(curr_level) == m.end()) {
            m[curr_level] = root->val;
        }
        
        dfs(root->right, m, curr_level + 1);
        dfs(root->left, m, curr_level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {        
        map<int, int> m;
        dfs(root, m, 0);
        
        vector<int> res;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            res.push_back(itr->second);
        }
        
        return res;                        
    }
};