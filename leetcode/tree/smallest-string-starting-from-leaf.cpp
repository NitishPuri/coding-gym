// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    void smallest_rec(TreeNode* root, string curr, string& smallest) {
        if(root == nullptr) return;
        
        curr += (char('a' + root->val));
        smallest_rec(root->left, curr, smallest);
        smallest_rec(root->right, curr, smallest);
        
        if(root->left == nullptr && root->right == nullptr) {
            reverse(curr.begin(), curr.end());
            if(smallest.empty() || smallest > curr) smallest = curr;
        }
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;
        smallest_rec(root, "", res);
        return res;
    }
};