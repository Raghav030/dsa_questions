//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int ffibonacci(int n, vector <int>& dp){
        int mod= 1e9+7;
        if (n==0) return 0;
        if (n==1) return 1;
        if (dp[n-1]!= -1) return dp[n-1];
        return dp[n-1] = ((ffibonacci(n-1, dp))%mod + (ffibonacci(n-2, dp))%mod)%mod;
    }
    int nthFibonacci(int n){
        // code here
        vector <int> dp(n, -1);
        // if (n==0) return 0;
        // if (n==1) return 1;
        // return ((nthFibonacci(n-1))%mod + (nthFibonacci(n-2))%mod)%mod;
        return ffibonacci(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends