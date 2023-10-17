//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fcycle (int v, vector <int> adj[], vector<int>& vect, stack<int> st){
        int cur= st.top();
        if (vect[cur]==2 or vect[cur]==1) return 1;
        if (vect[cur]==3) return 0;
        vect[cur]=1;// 1 means not a part of cycle
        for (int i=0; i<adj[cur].size(); i++){
            st.push(adj[cur][i]);
            if (fcycle(v, adj, vect, st)!=0){
                vect[cur]=2;//2 means part of circle
            }
            // cout<< fcycle(v, adj, vect, st);
            st.pop();
        }
        // cout<<cur;
        if (vect[cur]==1) {
            vect[cur]=3;
            return 0;
        }
        else return 1;
        // cout<< vect[cur];
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        stack <int> st;
        vector <int> vect(V, 0);
        vector <int> ans;
        for (int i=0; i<V; i++){
            if (vect[i]==0){
                st.push(i);
                fcycle(V, adj, vect, st);
                st.pop();
            }
        }
        for (int i=0; i<V; i++){
            // cout<< vect[i];
            if (vect[i]==3) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends