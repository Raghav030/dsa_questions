//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int fknapsack(int w, int n, int wt[], int val[], vector<vector<int>>& dp){
        if (n<=0) return 0;
        int take=0;
        if (dp[n][w]!= -1) return dp[n][w];
        if (w>= wt[n-1]){
            take= val[n-1]+ fknapsack(w-wt[n-1], n-1, wt, val, dp);
        }
        int nottake= fknapsack(w, n-1, wt, val, dp);
        return dp[n][w]= max(take, nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
       for (int i=0; i<=n; i++) dp[i][0]=0;
       for (int i=0; i<=W; i++) dp[0][i]=0;
       return fknapsack(W, n, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends