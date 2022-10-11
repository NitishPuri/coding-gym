// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// depth-first-search, breadth-first-search

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
    vector<int> count_rec(TreeNode* root, int distance, int& answer) {
        // if(root == nullptr) return 0;
        
        // list<int> res = {0};
        
        if(root->left == nullptr && root->right == nullptr) {
            return {1};
        }
        
        vector<int> left_res, right_res;
        if(root->left) {
            left_res = count_rec(root->left, distance, answer);
        }
        
        if(root->right) {
            right_res = count_rec(root->right, distance, answer);
        }
        
        vector<int> ret;
        for(auto itr = left_res.begin(); itr < left_res.end(); itr++) { 
            if(*itr > distance - 2) continue;
            ret.push_back(*itr + 1);
        }
        for(auto itr = right_res.begin(); itr < right_res.end(); itr++) { 
            if(*itr > distance - 2) continue;
            ret.push_back(*itr + 1);
        }
        
        for(auto itr_l = left_res.begin(); itr_l < left_res.end(); itr_l++) {
            if(*itr_l > distance - 1) continue;
            for(auto itr_r = right_res.begin(); itr_r < right_res.end(); itr_r++) {
                if(*itr_l + *itr_r <= distance) {
                    answer++;
                }
            }
        }
        
        
        return ret;

    }
    
public:
    int countPairs(TreeNode* root, int distance) {
        
        int answer = 0;
        count_rec(root, distance, answer);
        return answer;
        
    }
};