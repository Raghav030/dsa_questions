class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m= matrix[0].size();
        set<int> cset;
        set<int> rset;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] ==0){
                    rset.insert(i);
                    cset.insert(j);
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (rset.find(i)!= rset.end() or cset.find(j) != cset.end()) matrix[i][j]=0;
            }
        }
    }
};