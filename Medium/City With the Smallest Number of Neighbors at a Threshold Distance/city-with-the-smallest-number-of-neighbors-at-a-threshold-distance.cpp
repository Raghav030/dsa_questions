//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> graph(n, vector<int> (n,1e9));
        vector<vector<int>> graph1(n, vector<int> (n,1e9));
        vector<int> vect(n, 0);
        for (int i=0; i<m; i++){
            graph[edges[i][0]][edges[i][1]]= edges[i][2];
            graph[edges[i][1]][edges[i][0]]= edges[i][2];
        }
        for (int i=0; i<n; i++){
            graph[i][i]=0;
        }
        int temp=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    if (temp==0){
                        if (graph[j][i]+ graph[i][k]< graph[j][k]) graph1[j][k]= graph[j][i]+ graph[i][k];
                        else graph1[j][k]=graph[j][k];
                    }
                    else{
                        if (graph1[j][i]+ graph1[i][k]< graph1[j][k]) graph[j][k]= graph1[j][i]+ graph1[i][k];
                        else graph[j][k]=graph1[j][k];
                    }
                }
            }
            temp= 1-temp;
        }
        int ans=0;
        if (temp==0){
            for (int i=0; i<n; i++){
                ans=0;
                for (int j=0; j<n; j++){
                    if (graph[i][j]<=distanceThreshold) ans+=1;
                }
                vect[i]=ans;
            }
        }
        else{
            for (int i=0; i<n; i++){
                int ans=0;
                for (int j=0; j<n; j++){
                    if (graph1[i][j]<=distanceThreshold) ans+=1;
                }
                vect[i]=ans;
            }
        }
        temp=1e9;
        for (int i=n-1; i>=0; i--){
            if (vect[i]<temp){
                temp=vect[i];
                ans=i;
            }
            // cout<< i<< vect[i];
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends