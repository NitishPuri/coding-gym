// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

#include <vector>
#include <algorithm>
#include <iterator>
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
    void inorder(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);        
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {                
        vector<int> res1, res2, res;                
        inorder(root1, res1);
        inorder(root2, res2);        
        merge(res1.begin(), res1.end(), res2.begin(), res2.end(), back_inserter(res));                
        return res;        
    }
};