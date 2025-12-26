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
    ListNode* fnode(stack<ListNode*>& st, ListNode* nodeB){
        ListNode* ans=nullptr;
        if (nodeB->next) ans= fnode(st, nodeB->next);
        if (st.size()>0 and st.top()== nodeB) {
            st.pop();
            return nodeB;
        } 
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st;
        ListNode* nodeA= headA;
        ListNode* nodeB= headB;
        while (nodeA){
            st.push(nodeA);
            nodeA=nodeA->next;
        }
        return fnode(st, nodeB);
    }
};