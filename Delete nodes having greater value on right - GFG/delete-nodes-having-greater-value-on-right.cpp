//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* freverse(Node* head){
        Node* prev= nullptr;
        Node* next_node= head-> next;
        while (head){
            head->next= prev;
            prev=head;
            head=next_node;
            if (next_node) next_node= next_node->next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        // Node* listnode= head;
        // Node* prev= nullptr;
        Node* rev_head= freverse(head);
        head= rev_head;
        while (rev_head){
            while (rev_head-> next and rev_head-> next-> data< rev_head->data){
                rev_head->next= rev_head->next->next;
            }
            rev_head=rev_head->next;
        }
        return freverse(head);
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends