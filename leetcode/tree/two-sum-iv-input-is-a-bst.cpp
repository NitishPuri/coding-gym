// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// easy, hash-table, two-pointers, tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree

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
    void inorder(TreeNode* root, vector<int>& vec) {
        if(root == nullptr) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        
        int i = 0, j = vec.size() - 1;
        while(i < j) {
            auto sum = vec[i] + vec[j];
            if(sum == k) return true;
            else if(sum > k) --j;
            else ++i;
        }
        
        return false;
    }
};