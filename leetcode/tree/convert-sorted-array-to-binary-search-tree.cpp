// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// easy, array, divide-and-conquer, tree, binary-search-tree, binary-tree

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
    TreeNode* create_tree(vector<int>& nums, int start, int end) {
        if(start >= end) return nullptr;
        int mid = (start + end) / 2;
        return new TreeNode(nums[mid], create_tree(nums, start, mid), create_tree(nums, mid + 1, end));
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create_tree(nums, 0, nums.size());                
    }
};