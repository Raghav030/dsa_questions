//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int fproduct(int n, int m, int a[], int b[], vector<vector<int>>& dp){
	    if (n==0 or m==0) return 0;
	    if (dp[n][m] != -1) return dp[n][m];
	    int cur=0;
	    for (int i=n-1; i>=m-1; i--){
	        int temp= a[i]*b[m-1]+ fproduct(i, m-1, a, b, dp);
	        cur= max(cur, temp);
	    }
	    return dp[n][m]= cur;
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
		for (int i=1; i<m+1; i++){
		    for (int j=i; j<n+1; j++){
		        int take = 0;
		        if (j<n-(m-i-1)) take= dp[i-1][j-1]+ b[i-1]*a[j-1];
		        int nottake= dp[i][j-1];
		        dp[i][j]= max(take, nottake);
		    }
		}
		
	    return dp[m][n];
		
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends