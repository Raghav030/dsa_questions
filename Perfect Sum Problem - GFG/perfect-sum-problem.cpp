//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	void subsets (int cur, int arr[], int n, int sum, int i, int& ans){
	    if ((i>=n) or (cur>=sum and i<n and arr[i] !=0)){
	        if (cur==sum) ans+=1;
	        return;
	    }
	   // for (int j=i; j<n; j++){
	    subsets(cur+arr[i], arr, n, sum, i+1, ans);
	    subsets(cur, arr, n, sum, i+1, ans);
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // int cur=0;
        // int i=0;
        // int ans=0;
        // subsets(cur, arr, n, sum, i, ans);
        // return ans;
        int mod= 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        for (int i=0; i<n+1; i++){
            for (int j=0; j<sum+1; j++){
                if (i==0) dp[i][j]=0;
                if (j==0) dp[i][j]=1;
            }
        }
        for (int i=1; i<n+1; i++){
            for (int j=0; j<sum+1; j++){
                int take=0;
                if (j>= arr[i-1]) take=dp[i-1][j-arr[i-1]]%mod;
                int nottake= dp[i-1][j]%mod;
                dp[i][j]=(take+nottake)%mod;
            }
        }
        return dp[n][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends