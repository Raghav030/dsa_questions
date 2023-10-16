//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        vector <vector <int>> ans(n, vector<int>(n, 0));
        queue<int> q;
        for (int i=0; i<n; i++){
            q.push(i);
            vector <int> temp(n, 0);
            temp[i]=1;
            while (!q.empty()){
                int row= q.front();
                ans[i][row]=1;
                q.pop();
                for (int j=0; j<n; j++){
                    if (graph[row][j]==1 and temp[j]==0) {
                        q.push(j);
                        temp[j]=1;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends