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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow_ptr= head;
        ListNode* fast_ptr= head;
        if (head==nullptr )return nullptr;
        while (fast_ptr){
            slow_ptr= slow_ptr->next;
            fast_ptr= fast_ptr->next;
            if (fast_ptr) fast_ptr= fast_ptr->next;
            if (fast_ptr and slow_ptr==fast_ptr){
                slow_ptr=head;
                while (slow_ptr!= fast_ptr){
                    slow_ptr=slow_ptr->next;
                    fast_ptr= fast_ptr->next;
                }
                return slow_ptr;
            }
        }
        return nullptr;
    }
};