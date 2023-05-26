//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        Node* fast= head;
        Node* slow= head;
        int len=0;
        while (slow){
            slow=slow->next;
            len+=1;
        }
        slow=head;
        for (int i=1; i<len/2; i++){
            // fast=fast->next;
            slow=slow->next;
            // if (fast->next != nullptr) fast=fast->next;
        }
        Node* temp_node=slow->next;
        Node* temp= temp_node->next;
        while (temp_node){
            temp_node->next=slow;
            slow=temp_node;
            temp_node=temp;
            if (temp) temp=temp->next;
        }
        fast=slow;
        temp=head;
        for (int i=1; i<=len/2; i++){
            int num=temp->data;
            temp->data=slow->data-temp->data;
            slow->data=num;
            temp=temp->next;
            slow=slow->next;
        }
        temp_node=fast->next;
        slow=temp_node->next;
        fast->next=nullptr;
        while (fast != temp){
            temp_node->next=fast;
            fast=temp_node;
            temp_node=slow;
            slow=slow->next;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends