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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur_node= head;
        int num=0; 
        while (cur_node){
            cur_node=cur_node->next;
            num+=1;
        }
        if (num==0) return head;
        int num_rotate= k%num, nodes_after_cur=num-1;
        if (num_rotate==0) return head;
        cur_node=head;
        while (num_rotate != nodes_after_cur){
            cur_node=cur_node->next;
            nodes_after_cur-=1;
        }
        ListNode* new_head;
        new_head= cur_node->next;
        cur_node->next=nullptr;
        cur_node=new_head;
        while (cur_node->next) cur_node= cur_node->next;
        cur_node->next= head;
        return new_head;
    }
};