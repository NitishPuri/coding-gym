// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// hard, hash-table, tree, depth-first-search, breadth-first-search, binary-tree

#include <vector>
#include <map>
#include <set>

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
    map<int, map<int, multiset<int>>> m;
    void traverse_rec(TreeNode* root, int r, int c) {
        if(root == nullptr) return;
        m[c][r].insert(root->val);        
        traverse_rec(root->left, r + 1, c - 1);
        traverse_rec(root->right, r + 1, c + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {        
        traverse_rec(root, 0, 0);
        
        vector<vector<int>> ret;
        for(auto& it_c: m) {
            vector<int> ret_v;
            for(auto& it_r : it_c.second) {
                ret_v.insert(ret_v.end(), it_r.second.begin(), it_r.second.end());
            }
            ret.push_back(ret_v);
        }
        return ret;                        
    }
};