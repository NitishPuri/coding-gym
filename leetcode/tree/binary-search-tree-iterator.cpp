// https://leetcode.com/problems/binary-search-tree-iterator/
// medium, stack, tree, design, binary-search-tree, binary-tree, iterator

#include <stack>

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

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) { 
        pushLeft(root);
    }
    
    void pushLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
    
    int next() {
        if(!hasNext()) return -1;
        auto node = st.top(); st.pop();
        
        if(node->right != nullptr) {
            pushLeft(node->right);
        }
        
        return node->val;                                
    }
    
    bool hasNext() {
        return !(st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */