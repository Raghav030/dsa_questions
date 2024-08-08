class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int cur=1;
        int n=rows, m=cols, row=rStart, col=cStart;
        vector<vector<int>> ans;
        int flag=0;
        while(flag==0){
            flag= 1;
            for (int i=0; i<cur; i++){
                if (row>=0 and row<n and col>=0 and col<m) {
                    ans.push_back({row, col});
                    flag=0;
                }
                col+=1;
            }
            // col+=1;
            for (int i=0; i<cur; i++){
                if (row>=0 and row<n and col>=0 and col<m) {
                    ans.push_back({row, col});
                    flag=0;
                }
                row+=1;
            }
            cur+=1;
            // row+=1;
            for (int i=0; i<cur; i++){
                if (row>=0 and row<n and col>=0 and col<m) {
                    ans.push_back({row, col});
                    flag=0;
                }
                col-=1;
            }
            // col-=1;
            for (int i=0; i<cur; i++){
                if (row>=0 and row<n and col>=0 and col<m) {
                    ans.push_back({row, col});
                    flag=0;
                }
                row-=1;
            }
            // row-=1;
            cur+=1;
        }
        return ans;
    }
};