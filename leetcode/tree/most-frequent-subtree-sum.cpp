// https://leetcode.com/problems/most-frequent-subtree-sum/
// medium, hash-table, depth-first-search, tree, binary-tree

#include <vector>
#include <unordered_map>

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
    
    int sum_rec(TreeNode* root, unordered_map<int, int>& freq) {
        if(root == nullptr) return 0;        
        auto sum = sum_rec(root->left, freq) + sum_rec(root->right, freq) + root->val;        
        freq[sum]++;        
        return sum;                        
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        sum_rec(root, freq);        
        
        unordered_map<int, vector<int>> freq_inv;
        int max_freq = -1;
        for(auto itr = freq.begin(); itr != freq.end(); ++itr) {
            freq_inv[itr->second].push_back(itr->first);
            max_freq = max(max_freq, itr->second);
        }
        
        return max_freq != -1 ? freq_inv[max_freq] : vector<int>{};        
    }
};