// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// linked-list, two-pointers


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;     
        
        auto pseudo_head = new ListNode(-1000, head);
                                
        auto prev = pseudo_head;                        // .
        auto curr = prev->next;                         // 1
        auto next = curr->next;                         // 2
        while(next) {                                   
            bool d = false;
            while(next && curr->val == next->val) {
                d = true;
                next = next->next;
            }
            if(d) {
                prev->next = next;
                curr = next;
                next = next ? next->next : nullptr;
            } else {
                prev = curr;
                curr = next;
                next = curr->next;
            }            
        }
            
        return pseudo_head->next;
    }
};