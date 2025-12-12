class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        vector<int> rvect(n,1), cvect(m,1);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]==0){
                    rvect[i]=0;
                    cvect[j]=0;
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (rvect[i]==0 or cvect[j]==0) matrix[i][j]=0;
            }
        }
    }
};