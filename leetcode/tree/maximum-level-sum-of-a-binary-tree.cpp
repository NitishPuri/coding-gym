// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// medium, tree, depth-first-search, breadth-first-search, binary-tree

#include <vector>
#include <queue>

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
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        vector<int> level_sums;        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            auto size = q.size();
            int level_sum = 0;
            for(int i = 0; i < size; ++i) {
                auto node = q.front();
                
                level_sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                q.pop();
            }
            
            level_sums.push_back(level_sum);            
        }
        
        int max_sum = INT_MIN, max_sum_level = 0;
        for(int i = 0; i < level_sums.size(); ++i) {
            if(max_sum < level_sums[i]) {
                max_sum = level_sums[i];
                max_sum_level = i;
            }
        }
        
        return max_sum_level;        
    }
};

TreeNode* buildTree1() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    return root;
}

int main() {
    Solution s;
    s.maxLevelSum(buildTree1());
}