// https://leetcode.com/problems/unique-binary-search-trees-ii/


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
    vector<TreeNode*> generate_tree(int start, int end) {
        if(start > end) return {nullptr};
        
        if(start == end) return {new TreeNode(start, nullptr, nullptr)};
        
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i) {
            auto left_res = generate_tree(start, i-1);
            auto right_res = generate_tree(i+1, end);
            
            for(int j = 0; j < left_res.size(); ++j) {
                for(int k = 0; k < right_res.size(); ++k) {
                    res.push_back(new TreeNode(i, left_res[j], right_res[k]));                    
                }
            }
        }
        
        return res;        
    }
public:
    vector<TreeNode*> generateTrees(int n) {        
        vector<TreeNode*> ans = generate_tree(1, n);;
                
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.generateTrees(3);
    return 0;
}
