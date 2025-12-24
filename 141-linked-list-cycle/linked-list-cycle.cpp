/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow_ptr=head;
        ListNode* fast_ptr=head;
        if (head==nullptr or head->next==nullptr) return false;
        while (fast_ptr){
            // if (fast_ptr==slow_ptr) return true;
            fast_ptr=fast_ptr->next;
            slow_ptr= slow_ptr->next;
            if (fast_ptr) fast_ptr= fast_ptr->next;
            if (fast_ptr==slow_ptr) return true;
        } 
        return false;
    }
};