//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int maxi=0;
        for (int i=0; i<n; i++){
            maxi=max(maxi, price[i]);
        }
        // return maxi;
        vector <vector <int>> dp(n+1, vector<int>(n+1,0));
        for (int i=1; i<n+1; i++){
            for (int j=1; j<n+1; j++){
                int take=0;
                if (j>=i) take = dp[i][j-i]+ price[i-1];
                int nottake= dp[i-1][j];
                dp[i][j]=max(take, nottake);
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends