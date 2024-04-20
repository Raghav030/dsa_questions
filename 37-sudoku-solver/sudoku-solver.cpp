class Solution {
public:
bool checknum(char k, int row, int col, vector<vector<char>> board){
    for (int i=0; i<board.size(); i++){
        if (board[i][col]==k) return false;
        if (board[row][i]== k) return false;
        if (board[(row/3)*3+i/3][(col/3)*3+i%3]== k) return false;
    }
    return true;
}   
    bool fsudoko(vector<vector<char>>& board, int row, int col){
        int n= board.size();
        for(int i=row; i<n;i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j]=='.'){
                    for (char k='1'; k<='9'; k++){
                        if (checknum(k, i, j, board)==true) {
                            board[i][j]=k;
                            if (fsudoko(board, i, j)==true){
                                cout<<1;
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        cout<< static_cast<char>('0'+2);
        fsudoko(board, 0, 0);
        
    }
};