//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector <int> ans(N, 1e9);
        queue<pair<int,int>> q;
        vector <pair<int,int>> adj[N];
        for (int i=0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        q.push({0,0});
        while (!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            ans[node]=min(ans[node],dis);
            for (int i=0; i<adj[node].size(); i++){
                int t=adj[node][i].first;
                int index=0;
                for (index=0; index<adj[node].size(); index++){
                    if (adj[node][index].first==t) break;
                }
                // if (ans[t]>ans[node]+adj[node][index].second) 
                q.push({t,dis+adj[node][i].second});
            }
        }
        for (int i=0; i<N; i++){
            if (ans[i]==1e9) ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends