// https://leetcode.com/problems/serialize-and-deserialize-bst/

#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        
        string res;
        
        queue<TreeNode*> q;
        q.push(root);
        res += to_string(root->val) + ",";
        while(!q.empty()) {            
            auto node = q.front(); q.pop();
            if(node->left) {
                res += to_string(node->left->val) + ",";
                q.push(node->left);
            } else {
                res += "N,";
            }
            if(node->right) {
                res += to_string(node->right->val) + ",";
                q.push(node->right);
            } else {
                res += "N,";
            }                                    
        }
        
        return res;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
                
        int i = 0;
        while(data[i] != ',') ++i;
        auto root = new TreeNode(stoi(data.substr(0, i)));
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            
            int j = ++i;
            if(data[i] != 'N') {
                while(data[i] != ',') ++i;
                int val = stoi(data.substr(j, i));
                node->left = new TreeNode(val);
                q.push(node->left);
            } else {
                ++i;
            }
            
            j = ++i;
            if(data[i] != 'N') {
                while(data[i] != ',') ++i;
                int val = stoi(data.substr(j, i));
                node->right = new TreeNode(val);
                q.push(node->right);
            } else {
                ++i;
            }                        
        }
                        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;