// https://leetcode.com/problems/find-mode-in-binary-search-tree/
// easy, tree, depth-first-search, binary-search-tree, binary-tree

#include <vector>
#include <unordered_map>
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
    void inorder(TreeNode* root, unordered_map<int, int>& m) {
        if(root == nullptr) return;
        
        inorder(root->left, m);
        m[root->val]++;
        inorder(root->right, m);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        inorder(root, m);        
        map<int, vector<int>> fm;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            fm[itr->second].push_back(itr->first);
        }        
        return fm.rbegin()->second;
    }
};