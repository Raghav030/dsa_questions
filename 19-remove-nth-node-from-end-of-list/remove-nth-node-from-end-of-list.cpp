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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=0;
        ListNode* node= head;
        while (node){
            node=node->next;
            num+=1;
        }
        if (n>num) return nullptr;
        n = num- n+1;
        cout<<n<< num;
        // swap(n, num);
        node= head;
        if (n==1) return head->next;
        while (node){
            if (n==2 and n !=num) {
                node->next= node->next->next;
                break;
            }
            if (n==2){
                node->next=nullptr;
                break;
            }
            n-=1;
            node=node->next;
        }
        return head;
    }
};