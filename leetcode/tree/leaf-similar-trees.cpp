// https://leetcode.com/problems/leaf-similar-trees/
// easy, tree, depth-first-search, binary-tree

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
    void getLeafNodes(TreeNode* root, vector<int>& leaf_nodes) {
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr) {
            leaf_nodes.push_back(root->val);
            return;
        }
        
        getLeafNodes(root->left, leaf_nodes);    
        getLeafNodes(root->right, leaf_nodes);    
    }
    
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeafNodes(root1, leaf1);
        getLeafNodes(root2, leaf2);
        
        if(leaf1.size() != leaf2.size()) return false;
        
        for(int i = 0; i < leaf1.size(); ++i) {
            if(leaf1[i] != leaf2[i]) return false;
        }
        
        return true;
        
    }
};