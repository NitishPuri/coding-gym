// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

// LL
// RL

// LL
// LLL

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
    bool search(TreeNode* root, int val, string& path) {
        if(root == nullptr) return false;
        
        if(root->val == val) {
            return true;
        }
        
        if(search(root->left, val, path)) {
            path.append("L");
            return true;
        }
        
        if(search(root->right, val, path)) {
            path.append("R");
            return true;
        }
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path1, path2;
        search(root, startValue, path1);
        search(root, destValue, path2);
        
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());
        
        int i = 0;
        while(i < path1.length() && i < path2.length() && path1[i] == path2[i]) ++i;
        
        string res;
        for(int j = i; j < path1.length(); ++j) res += "U";
        res += path2.substr(i);
        
        return res;
        
        
    }
};