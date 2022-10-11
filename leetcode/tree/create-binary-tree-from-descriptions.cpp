// https://leetcode.com/problems/create-binary-tree-from-descriptions/
// medium, array, hash-table, tree, depth=first-search, breadth-first-search, binary-tree

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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        
        unordered_map<int, pair<TreeNode*, int> > m;        
        for(int i = 0; i < d.size(); ++i) {
            if(m.find(d[i][0]) == m.end()) m[d[i][0]] = { new TreeNode(d[i][0]), -1 };
            if(m.find(d[i][1]) == m.end()) m[d[i][1]] = { new TreeNode(d[i][1]), -1 };
            
            if(d[i][2] == 1) {
                m[d[i][0]].first->left = m[d[i][1]].first;    
            } else {
                m[d[i][0]].first->right = m[d[i][1]].first;    
            }
            m[d[i][1]].second = d[i][0];            
        }
        
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            if(itr->second.second == -1) return itr->second.first;
        }
        
        return nullptr;
        
    }
};