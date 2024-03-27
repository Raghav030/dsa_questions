//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int traverse(vector<vector<int>> mat, int i, int j, int rows, int cols){
        int nextup=1e9;
        int nextdown=1e9;
        int nextright=1e9;
        if (j==cols-1) return 1;
        if (j+1>=0 and j+1<cols && mat[i][j+1]==1){
            mat[i][j]=-1;
            nextright= traverse(mat, i, j+1, rows, cols);
            mat[i][j]=1;
        }
        if (i+1>=0 && i+1 <rows && mat[i+1][j]==1){
            mat[i][j]=-1;
            nextdown= traverse(mat, i+1, j, rows, cols);
            mat[i][j]=1;
        }
        if (i-1>=0 and i-1<rows && mat[i-1][j]==1){
            mat[i][j]=-1;
            nextup= traverse(mat, i-1, j, rows, cols);
            mat[i][j]=1;
        }
        int cur= min(nextup, nextdown);
        cur= min(cur, nextright);
        // if (cur>=1e9) return mat[i][j]=-1;
        return (1+ cur);
    }
    int findShortestPath(vector<vector<int>> mat)
    {
       // code here
       int rows= mat.size();
       int cols= mat[0].size();
       vector<int> rvect={0, -1, 1,0};
       vector<int> cvect={1, 0, -1, 0};
       for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (mat[i][j]==1){
                    for (int k=0; k<4; k++){
                        int rnext=i+ rvect[k];
                        int cnext= j+ cvect[k];
                        if (rnext>=0 && cnext>=0 && rnext<rows && cnext< cols){
                            if (mat[rnext][cnext]==0 ){
                                mat[i][j]=2;
                                break;
                            }
                        }
                    }
                }
            }    
       }
       for (int i=0; i<rows; i++){
           for (int j=0; j<cols; j++){
               if (mat[i][j]==0 || mat[i][j]==2) mat[i][j]=-1;
           }
       }
    //   for (int i=0; i<rows; i++){
    //       for (int j=0; j<cols; j++){
    //           cout<< mat[i][j]<<" ";
    //       }
    //       cout<< endl;
    //   }
       if (mat.size()==0) return 0;
       int ans=1e9;
       for (int i=0; i<rows; i++){
          int cur=1e9;
          if (mat[i][0]==1 && mat[i][1]==1){
              if (rows==1) return 1;
              cur= 1+ traverse(mat, i,1, rows, cols);
          }
          ans= min(ans, cur);
       }
       if (ans==1e9) return -1;
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends