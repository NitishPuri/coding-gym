// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// string, depth-first-search, breadth-first-search, design, binary-tree, hard

#include <iostream>
#include <string>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        string result;
                
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if(curr == nullptr) {
                result += ". ";
                continue;
            }
            result += to_string(curr->val) + " ";
            
            q.push(curr->left);
            q.push(curr->right);            
        }
        
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        
        TreeNode* root = nullptr;;        
        // TreeNode* curr = root;
        
        queue<TreeNode*> q;        
        int i = 0;
                
        auto read_next = [&]() -> TreeNode* {
            if(data[i] == '.') {
                i+=2;
                return nullptr;
            }
            
            bool neg = false;
            if(data[i] == '-') {
                neg = true;
                i++;
            }
            // get val
            int val = 0;
            while(data[i] >= '0' && data[i] <= '9') {
                val = val*10 + (data[i] - '0');
                i++;
            }
            if(neg) val *= -1;
            i++;  // ' '
            return new TreeNode(val);
        }; 
        
        root = read_next();
        q.push(root);            
                
        while( !q.empty() && i < data.length()) {
            
            int size = q.size();
            for(int j = 0; j < size; j++) {
                TreeNode* curr_parent = q.front(); //q.pop();            

                curr_parent->left = read_next();
                curr_parent->right = read_next();

                int nodes_added = 0;
                if(curr_parent->left) {
                    q.push(curr_parent->left);
                    nodes_added++;
                }
                if(curr_parent->right) {
                    q.push(curr_parent->right);
                    nodes_added++;
                }

                q.pop();                
            }                                            
            // i++;  // ' '
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    cout << "Serialization\n";

    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(22);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "Tree Created\n";

    Codec c;

    string root_data = c.serialize(root);

    cout << root_data << endl;

    auto root_copy = c.deserialize(root_data);

    cout << c.serialize(root_copy);
}