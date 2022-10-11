// https://leetcode.com/problems/print-binary-tree/
// medium, tree, depth-first-search, breadth-first-search, binary-tree

#include <vector>
#include <string>

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
    int height(TreeNode* root) {
        if(root == nullptr) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void print(TreeNode* root, int r, int c, int h, vector<vector<string>>& res) {
        if(root == nullptr) return;        
        res[r][c] = to_string(root->val);        
        
        if(r == h) return;        
        int d = (1 << (h - r - 1));
        print(root->left, r + 1, c - d, h, res);
        print(root->right, r + 1, c + d, h, res);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {                
        int h = height(root);
        int m = h + 1;
        int n = (1<<m) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        print(root, 0, (n-1)/2, h, res);                                        
        return res;
    }
};