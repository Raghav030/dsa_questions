/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_ptr= nullptr;
        ListNode* cur_ptr=head;
        if(head==nullptr) return nullptr;
        if (head->next== nullptr) return head;
        ListNode* next_ptr=nullptr;
        if (head->next ) next_ptr=head->next;
        while(cur_ptr){
            // if (prev_ptr== nullptr) cur_ptr->next=nullptr;
            cur_ptr->next=prev_ptr;
            prev_ptr=cur_ptr;
            cur_ptr= next_ptr;
            if(next_ptr) next_ptr= next_ptr->next;
        }
        return prev_ptr;
    }
};