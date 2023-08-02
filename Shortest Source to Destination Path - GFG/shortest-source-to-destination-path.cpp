//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0,0}});
        vector<vector<int>> vis(N, vector<int>(M,0));
        while (!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            if (row==X and col==Y) return distance;
            q.pop();
            vector<int> rvect={0, -1, 0, 1};
            vector<int> cvect={1, 0, -1, 0};
            for (int i=0; i<4; i++){
                int rnext=row+rvect[i];
                int cnext=col+cvect[i];
                if (rnext>=0 and cnext>=0 and rnext< N and cnext<M and A[rnext][cnext]==1 and vis[rnext][cnext]==0){
                    q.push({distance+1, {rnext, cnext}});
                    vis[rnext][cnext]=1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends