//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int fparent (int node, vector<int>& parent){
	    if (parent[node]==node) return node;
	    return parent[node]=fparent(parent[node], parent);
	}
	void findunion(int weight, int n1, int n2, vector <int>& parent, vector<int>& rank, int& ans){
	    int pn1=fparent(n1, parent);
	    int pn2=fparent(n2, parent);
	    if (pn1==pn2) return;
	    ans+=weight;
	    if (rank[n1]<rank[n2]){
	        parent[pn1]=pn2;
	    }
	    else if (rank[n1]>rank[n2]){
	        parent[pn2]=pn1;
	        
	    }
	    else {
	        parent[pn2]=pn1;
	        rank[pn1]+=1;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // priority_queue <pair<int,pair<int,int>>, vector<int,pair<int,int>>, greater<int,pair<int,int>>> pq;
        vector <pair<int, pair<int, int>>> nodes;
        for (int i=0; i<V; i++){
            for (int j=0; j<adj[i].size(); j++){
                nodes.push_back({adj[i][j][1], {i, adj[i][j][0]}});
            }
        }
        int ans=0;
        sort(nodes.begin(), nodes.end());
        vector <int> parent(V+1,0);
        vector <int> rank(V+1,0);
        for (int i=0; i<parent.size(); i++){
            parent[i]=i;
        }
        for (int i=0; i<nodes.size(); i++){
            findunion(nodes[i].first, nodes[i].second.first, nodes[i].second.second,parent , rank, ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends