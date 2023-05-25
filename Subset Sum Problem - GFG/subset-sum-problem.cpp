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
        vector<vector<int>>dp (arr.size()+1, vector<int> (sum+1, -1));
        return fsum(arr, sum, dp, n);
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