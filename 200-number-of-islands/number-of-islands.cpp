class Solution {
public:
    void markisland(int row, int col, vector<vector<char>>& grid){
        vector<int> rvect={0, -1, 0, 1};
        vector<int> cvect= {1, 0, -1, 0};
        grid[row][col]='2';
        // queue<pair<int, int>> q;
        // q.push({row, col});
        // while (q.size()>0){
        //     row=q.front().first;
        //     col= q.front().second;
        //     q.pop();
        //     grid[row][col]='2';
        //     for(int i=0; i<4; i++){
        //         int rnext= row+ rvect[i];
        //         int cnext= col+ cvect[i];
        //         if (rnext>=0 and cnext>=0 and rnext< grid.size() and cnext<grid[0].size() and grid[rnext][cnext]=='1'){
        //             q.push({rnext, cnext});
        //         }
        //     }
        // }
        for (int i=0; i<4; i++){
            int rnext= row+rvect[i];
            int cnext= col+ cvect[i];
            if (rnext>=0 and cnext>=0 and rnext<grid.size() and cnext<grid[0].size() and grid[rnext][cnext]=='1'){
                grid[rnext][cnext]='2';
                markisland(rnext, cnext, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]=='1'){
                    ans+=1;
                    markisland(i, j, grid);
                }
            }
        }
        return ans;
    }
};