//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> finorder(stack<Node*>& st1, stack<Node*>& st2){
        vector <int> ans;
        while (st1.size()>0 and st2.size()>0){
            Node* root1= st1.top();
            Node* root2= st2.top();
            if (st1.top()->data == st2.top()->data){
                ans.push_back(st1.top()->data);
                // st1.pop();
                // st2.pop();
                next_node(st1);
                next_node(st2);
            }
            else if (st1.top()->data< st2.top()->data){
                // st1.pop();
                next_node(st1);
            }
            else if (st1.top()->data> st2.top()->data){
                // st2.pop();
                next_node(st2);
            }
        }
        return ans;
        
    }
    void next_node (stack<Node*>& st){
        if (st.top()==nullptr) return;
        Node* node= st.top();
        st.pop();
        // Node* root= st.top();
        if (node->right==nullptr) return;
        st.push(node->right);
        while (st.top()->left){
            st.push(st.top()->left);
        }
    }
    // void fcheck(Node* root1, Node* root2){
    //     if (node1->data==node2-> data){
    //         ans.push_back(node1->data);
    //     }
        
    // }
    vector <int> findCommon(Node *root1, Node *root2)
    {
    //Your code here
    stack<Node*> st1;
    stack<Node*> st2;
    while (root1!=nullptr) {
        st1.push(root1);
        root1=root1->left;
    }
    while (root2 !=nullptr) {
        st2.push(root2);
        root2=root2->left;
    }
    return finorder(st1, st2);
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends