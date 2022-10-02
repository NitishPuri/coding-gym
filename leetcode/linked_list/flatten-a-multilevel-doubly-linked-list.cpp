// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        auto curr = head;
        Node* next = nullptr;
        while(curr) {
            if(curr->child) {
                auto curr_next = curr->next;
                auto curr_child = flatten(curr->child);
                curr->next = curr_child;
                curr_child->prev = curr;
                curr->child = nullptr;
                while(curr_child->next) {
                    curr_child = curr_child->next;
                }
                curr_child->next = curr_next;
                if(curr_next)
                    curr_next->prev = curr_child;                
            }
            curr = curr->next;
        }
        return head;
    }
};