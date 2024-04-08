//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int famount(int i, int j, int arr[], vector<vector<int>>& dp){
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int l1=famount(i+2, j, arr, dp);
        int l2= famount(i+1, j-1, arr, dp);
        int r1=famount(i,j-2, arr, dp);
        int r2=famount(i+1, j-1, arr, dp);
        int left= arr[i]+ min(l1,l2 );
        int right= arr[j]+ min(r1, r2);
        return dp[i][j]= max(left, right);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return famount(0, n-1, arr, dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends