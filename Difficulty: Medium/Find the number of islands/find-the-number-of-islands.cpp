//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void markisland(vector<vector<char>>& grid, int row, int col, int n, int m){
        vector<int> rvect= {-1, 0, 1, 0, 1, 1, -1, -1};
        vector<int> cvect= {0, -1, 0, 1, 1, -1, -1, 1};
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            grid[r][c]='2';
            for (int i=0; i<8; i++){
                int rnext= r+ rvect[i];
                int cnext = c+cvect[i];
                if (rnext <n and cnext <m and rnext >=0 and cnext >= 0 and grid[rnext][cnext]=='1'){
                    grid[rnext][cnext]='2';
                    q.push({rnext, cnext});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size(), m=grid[0].size(), ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]=='1'){
                    markisland(grid, i,j, n, m);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends