//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fmaxival(int N, int W, int val[], int wt[], vector <vector<int>>& dp){
       if (N<=0 or W<=0) return 0;
       int take=0;
       int cur_weight=W;
       if (dp[N][W]!=-1) return dp[N][W];
       if (W-wt[N-1] >=0){
        //   cout<<N<<W;
           take =val[N-1] + fmaxival(N, W-wt[N-1], val, wt, dp);
        //   take=max(take, temp);
        //   cur_weight-=wt[N-1];
       }
       int nottake= fmaxival(N-1, W, val, wt, dp);
       return dp[N][W]= max(take, nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector <vector <int>> dp(N+1, vector <int> (W+1,-1));
        for (int i=0; i<N;i++){
            for (int j=0; j<W; j++){
                if (i==0 or j==0) dp[i][j]=0;
            }
        }
        fmaxival(N, W, val, wt, dp);
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends