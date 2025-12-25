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
    bool fisPalindrome(ListNode* node_from_last, ListNode* &node_from_start){
        bool result = true;
        if (node_from_last->next) result= fisPalindrome(node_from_last->next, node_from_start);
        if (result==false) return false;
        cout<< node_from_last->val<< node_from_start->val<<endl;
        if (node_from_last->val != node_from_start->val) return false;
        node_from_start= node_from_start->next;
        return true;

    }
    bool isPalindrome(ListNode* head) {
        return fisPalindrome(head, head);
    }
};