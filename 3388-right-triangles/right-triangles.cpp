class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans=0;
        int n= grid.size();
        int m= grid[0].size();
//         for (int i=0; i< n-1; i++){
//             for (int j=0; j<n-1; j++){
//                 if ((grid[i][j]==1 and (grid[i][j]==grid[i][j+1] and grid[i][j]==grid[i+1][j]) or (grid[i+1][j+1]==1 and grid[i+1][j]== grid[i+1][j+1] and grid[i+1][j]== grid[i][j+1]) or ( grid[i][j]==1 and grid[i+1][j]== grid[i][j] and grid[i][j]== grid[i+1][j+1]) or (grid[i][j]==1 and grid[i][j]==grid[i][j+1] and grid[i][j]== grid[i+1][j+1]))) ans+=1;
                
//             }
            
//         }
//         return ans;
        vector<int > rvect(n, 0);
        vector<int> cvect(m, 0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==1){
                    rvect[i]+=1;
                    cvect[j]+=1;
                }
            }
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                long long temp= 1LL* (rvect[i]==0 or cvect[j]==0 )?1LL* 0: 1LL*(rvect[i]-1)*(cvect[j]-1);
                
                if (grid[i][j]==1) ans= ans+ temp;
            }
        }
        return ans;
    }
};