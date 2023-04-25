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
        int V=N;
        set <pair<int,int>> s;
        vector <int> dis(V,1e9);
        s.insert({0,0});
        dis[0]=0;
        while (!s.empty()){
            auto it=*(s.begin());
            int distance=it.first;
            int node=it.second;
            // dis[node]=distance;
            s.erase({distance,node});
            for (int i=0; i<adj[node].size();i++){
                int t=adj[node][i].first;
                if (dis[node]+adj[node][i].second<dis[t]){
                    if (dis[t]!=1e9){
                        s.erase({dis[t],t});
                    }
                    s.insert({distance+adj[node][i].second,t});
                    dis[t]=dis[node]+adj[node][i].second;
                }
            }
        }
        for (int i=0; i<dis.size(); i++){
            if (dis[i]==1e9) dis[i]=-1;
        }
        return dis;
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