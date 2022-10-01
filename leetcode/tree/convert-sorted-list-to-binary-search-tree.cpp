// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    TreeNode* sortedListToBST_rec(ListNode* head, int num_nodes) {
        
        if(head == nullptr) return nullptr;
        if(num_nodes <= 0) return nullptr;
        
        // find root
        int i = num_nodes/2;
        auto curr = head;
        while(i--) { curr = curr->next; }
        
        TreeNode* new_node = new TreeNode(curr->val);
        new_node->left = sortedListToBST_rec(head, num_nodes/2);
        new_node->right = sortedListToBST_rec(curr->next, (num_nodes % 2 == 0 ? num_nodes/2 - 1 : num_nodes/2));   
        
        return new_node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        // count nodes
        int num_nodes = 0;
        auto curr = head;
        while(curr) {
            num_nodes++; 
            curr = curr->next;
        }
        
        return sortedListToBST_rec(head, num_nodes);                                                        
    }
};

int main() {
    Solution s;
    vector<int> input({-10,-3,0,5,9});
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for(int i = 0; i < input.size(); i++) {
        auto next = new ListNode(input[i]);
        if(head == nullptr) head = next;
        else curr->next = next;
        curr = next;
    }
    auto res = s.sortedListToBST(head);
}