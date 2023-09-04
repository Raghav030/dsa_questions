//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void fbfs(vector <vector <char>>& mat, vector <vector <int>>& vis, int row, int col){
        vector <int> rvect={0, -1, 0, 1};
        vector <int> cvect={-1, 0, 1, 0};
        queue <pair<int, int>> q;
        int n= mat.size();
        int m= mat[0].size();
        int flag=1;
        vis[row][col]=1;
        if (row==0 or row==n-1 or col==0 or col==m-1) flag=0;
        q.push({row, col});
        while (!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            if (flag==1) mat[row][col]='X';
            q.pop();
            for (int i=0; i<4; i++){
                int rnext= row+ rvect[i];
                int cnext= col+ cvect[i];
                if (rnext>=0 and rnext<n and cnext>=0 and cnext<m and mat[rnext][cnext]=='O' and vis[rnext][cnext]==0){
                    q.push({rnext, cnext});
                    vis[rnext][cnext]=1;
                }
            }
            
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector <vector <int>> vis(n, vector <int>(m, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if ((i==0 or i==n-1 or j==0 or j==m-1) and vis[i][j]==0 and mat[i][j]=='O') fbfs(mat, vis, i, j);
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (vis[i][j]==0 and mat[i][j]=='O') fbfs(mat, vis, i, j);
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends