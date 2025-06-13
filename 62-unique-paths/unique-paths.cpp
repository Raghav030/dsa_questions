class Solution {
public:
    int fpaths (int m, int n, int row, int col, vector<vector<int>>& dp){
        if ((row>=m or col>=n)) return 0;
        if (row==m-1 and col==n-1) return 1;
        if (dp[row][col]>0) return dp[row][col];
        int down=0;
        int left =0;
        if (m-1>row) down= fpaths(m,n, row+1, col, dp);
        if (col<n-1) left= fpaths(m,n, row, col+1, dp);
        return dp[row][col]=left + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // cout<< dp[m-1][n-2];
        return fpaths(m, n, 0, 0, dp);

    }
};