class Solution {
public:
    bool checkposition(int row, int col, vector<string>& vect, int n){
        for (int i=0; i<n; i++){
            if (vect[i][col]=='Q') return false;
        }
        int i=row, j=col;
        while (i>=0 and j>=0 and i<n and j<n){
            if (vect[i][j]=='Q') return false;
            i-=1;
            j-=1;
        }
        i=row, j=col;
        while (i>=0 and j>=0 and i<n and j<n){
            if (vect[i][j]=='Q') return false;
            i-=1;
            j+=1;
        }
        return true;
    }
    void fnqueen(int n, int row,vector<string>& vect,  int& ans){
        if (row== n){
            ans+=1;
        }
        for (int i=0; i<n; i++){
            if (checkposition(row,i, vect, n)==true){
                vect[row][i]='Q';
                fnqueen(n, row+1, vect, ans);
                vect[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string> vect(n, string(n, '.'));
        fnqueen(n, 0,vect, ans);
        return ans;
    }
};