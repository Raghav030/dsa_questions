//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool fsum(vector<int> arr, int sum, vector<vector<int>>& dp, int n){
        if (sum==0) return true;
        if (n==0 or sum<0) return false;
        if (dp[n][sum] != -1) return dp[n][sum];
        if (fsum(arr, sum-arr[n-1], dp, n-1)==1) return dp[n][sum]=1;
        if (fsum(arr, sum, dp, n-1)==1) return dp[n][sum]= 1;
        return dp[n][sum]= 0;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp (arr.size()+1, vector<bool> (sum+1));
        // return fsum(arr, sum, dp, n);
        for (int i=0; i<n; i++){
            for (int j=0; j<sum+1; j++){
                if (i==0) dp[i][j]=false;
                if (j==0) dp[i][j]=true;
            }
        }
        for (int i=1; i<n+1; i++){
            for (int j=1; j<sum+1; j++){
                bool take=false;
                if (j>=arr[i-1]) take=dp[i-1][j-arr[i-1]];
                bool nottake= dp[i-1][j];
                dp[i][j]= take or nottake;
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends