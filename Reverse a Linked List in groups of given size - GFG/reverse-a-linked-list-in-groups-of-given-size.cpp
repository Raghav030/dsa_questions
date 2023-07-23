//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* prev=nullptr;
        node* cur_node=head;
        node* next_node=head->next;
        int flag=1;
        node* last_first=nullptr;
        while (cur_node != nullptr){
            // for (int i=0; i<k-1; i++){
            //     prev=prev->next;
            //     cur_node=cur_node->next;
            //     next_node=next_node->next;
            // }
            // next_first=next_node;
            // cur_node->next=last_last;
            node* cur_first=cur_node;
            for (int i=0; i<k; i++){
                
                if (cur_node != nullptr){
                    // if (last_last) last_last->next=cur_node;
                    cur_node->next=prev;
                    // last_last=cur_node;
                    prev=cur_node;
                    cur_node=next_node;
                    if (next_node) next_node=next_node->next;
                }
            }
            if (last_first){
                
                last_first->next=prev;
            }
            last_first=cur_first;
            if (flag==1){
                head=prev;
                flag+=1;
            }
            prev=nullptr;
                // cur_node=next_node;
                // if (next_node) next_node=next_node->next;
            
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends