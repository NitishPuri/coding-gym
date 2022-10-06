// https://leetcode.com/problems/sum-root-to-leaf-numbers/


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
    void sum_rec(TreeNode* root, int parent_num, int& sum) {
        if(root == nullptr) return;
        
        int curr_num = (parent_num + root->val);
        
        if(root->left == nullptr && root->right == nullptr) {
            sum += curr_num;    
            return;
        }
        
        curr_num *= 10;
        
        sum_rec(root->left, curr_num, sum);
        sum_rec(root->right, curr_num, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sum_rec(root, 0, sum);
        return sum;
    }
};