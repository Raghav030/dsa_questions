//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    void inorder(Node* root, vector<int>& vect){
        if (root==nullptr) return;
        inorder(root->left, vect);
        vect.push_back(root->data);
        inorder(root->right, vect);
    }
    void merge(vector<int>& vect, int s, int m, int l, int& ans){
        vector<int> temp;
        int j=m +1;
        int i=s;
        while (i<=m and j<=l){
            if (vect[i]>vect[j]) ans=ans+m-i+1;
            if (vect[i]<vect[j]){
                temp.push_back(vect[i]);
                i+=1;
            }
            else{
                temp.push_back(vect[j]);
                j+=1;
            }
        }
        while (i<=m){
            temp.push_back(vect[i]);
            i+=1;
        }
        while(j<=l){
            temp.push_back(vect[j]);
            j+=1;
        }
        for(j=s; j<=l; j++){
            vect[j]=temp[j-s];
        }
    }
    void mergesort(vector<int>& vect, int s, int l, int& ans){
        if (l<=s) return;
        int m=(s+l)/2;
        mergesort(vect, s, m, ans);
        mergesort(vect, m+1, l, ans);
        merge(vect, s, m , l, ans);
    }
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> vect;
        inorder(root, vect);
        int ans=0;
        mergesort(vect, 0, n-1, ans);
        // for (int i=0;i<n; i++){
        //     cout<<vect[i]<<' ';
        //     for (int j=i+1; j<n; j++){
        //         if (vect[i]>vect[j]){ 
        //             // ans+=1;
        //             // cout<<vect[i]<<vect[j]<<' ';
        //         }
        //     }
        // }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends