/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        Node* new_head= new Node(0), *cur_node=head, *cur_new_node=nullptr;
        if (head== nullptr) return nullptr;
        while (cur_node){
            if (cur_node==head){
                // cout<<1;
                // Node* new_head;
                
                new_head->val= head->val;
                cur_new_node= new_head;
            }
            else {
                // cout<<2;
                Node* new_node=new Node(0);
                new_node->val= cur_node->val;
                cur_new_node->next=new_node;
                cur_new_node= cur_new_node->next;
            }
            mpp.insert({cur_node, cur_new_node});
            cur_node=cur_node->next;
        }
        cur_new_node= new_head;
        cur_node= head;
        while (cur_new_node){
            if (cur_node->random==nullptr) cur_new_node->random=nullptr;
            else{
                cur_new_node->random= mpp[cur_node->random];
            }
            cur_node= cur_node->next;
            cur_new_node= cur_new_node->next;
        }
        return new_head;
    }
};