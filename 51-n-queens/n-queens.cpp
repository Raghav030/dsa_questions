class Solution {
public:
    bool checkposition(vector<string>& vect, int row, int col, int n){
        // for (int i=0; i<n; i++){
        //     if (vect[row][i]=='Q') return false;
        // }
        for (int i=0; i<n; i++){
            if (vect[i][col]=='Q') return false;
        }
        int i=row, j=col;
        while (i>=0 and j>=0 and i<n and j<n){
            if (vect[i][j]=='Q') return false;
            i+=1;
            j-=1;
        }
        i=row, j=col;
        while (i>=0 and j>=0 and i<n and j<n){
            if (vect[i][j]=='Q') return false;
            i+=1;
            j+=1;
        }
        i=row, j=col;
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
    void fnqueens(int n, int row, int col, vector<string>& vect, vector<vector<string>>& ans){
        if (n==row){
            ans.push_back(vect);
            return;
        }
        for (int i=0; i<n; i++){
            if (checkposition(vect, row, i, n)==true){
                vect[row][i]='Q';
                fnqueens(n, row+1,col, vect, ans);
                vect[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> vect(n,string(n, '.'));
        // for (int i=0; i<n; i++){
        //     vector<string> vect(n,string(n, '.'));
        //     // for (int i=0; i<n; i++){
        //     //     for (int j=0; j<n; j++){
        //     //         cout<< vect[i]<<' ';
        //     //     }
        //     //     cout<< endl;
        //     // }
        //     vect[0][i]='Q';
        //     int flag=0;
        //     for (int k=1; k<n; k++){
        //         flag=0;
        //         for (int j=0; j<n; j++){
        //             if (checkposition(vect, k, j, n)){
        //                 vect[k][j]='Q';
        //                 flag=1;
        //                 break;
        //             }
        //         }
        //         if (flag==0) break;
        //     }
        //     if (flag==1 or n==1){
        //         ans.push_back(vect);
        //     }
        // }
        fnqueens(n, 0, 0, vect, ans);
        return ans;
        
    }
};