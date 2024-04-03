class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<int>>& visited, int i, int row, int col){
        vector<int> cvect={0, -1, 0, 1};
        vector<int> rvect={-1, 0, 1, 0};
        if (i>=word.size()) return true;
        visited[row][col]=1;
        for (int j=0; j<4; j++){
            int rnext= rvect[j]+ row;
            int cnext= cvect[j]+col;
            if (rnext>=0 and cnext>=0 and rnext<board.size() and cnext<board[0].size() and visited[rnext][cnext]==0 and board[rnext][cnext]== word[i]){
                visited[rnext][cnext]=1;
                bool ans= dfs(board, word, visited,i+1, rnext, cnext);
                if (ans==true) return true;
                visited[rnext][cnext]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m= board[0].size();
        int count=0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == word[0]){
                    visited[i][j]=1;
                    bool ans= dfs(board, word, visited, 1, i, j);
                    if (ans==true) return true;
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};