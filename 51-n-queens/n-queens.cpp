class Solution {
public:
    bool checkposition(int row, int col, vector<string> grid){
        for (int i=0; i<grid.size(); i++){
            if (grid[row][i]=='Q') return false;
            if (grid[i][col]=='Q') return false;
        }
        int i=row, j=col;
        while (i>=0 and j>=0 and i<grid.size() and j<grid.size()){
            if (grid[i][j]=='Q') return false;
            i-=1;
            j-=1;
        }
        i=row;
        j=col;
        while (i>=0 and j<grid.size() and i<grid.size() and j>=0){
            if (grid[i][j]=='Q') return false;
            i-=1;
            j+=1;
        }
        return true;
    }
    void fnqueens(int n, int row, vector<string>& grid, vector<vector<string>>& ans){
        if (n==row){
            ans.push_back(grid);
            return;
        }
        for (int i=0; i<n; i++){
            if (checkposition(row, i, grid)==true){
                grid[row][i]='Q';
                fnqueens(n, row+1, grid, ans);
            }
            grid[row][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        fnqueens(n, 0, grid, ans);
        return ans;
    }
};