//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for (int i=0; i<n; i++){
            sum+=arr[i];
        }
        // return sum;
        int mod=1e9+7;
        if ((sum%2==0 and d%2==1) or (sum%2==1 and d%2==0)) return 0;
        int maxsum= (sum+d)/2;
        vector<vector<int>> dp (n+1, vector<int>(maxsum+1, 0));
        for (int i=0; i<n+1; i++){
            for (int j=0; j<maxsum+1; j++){
                if (i==0) dp[i][j]=0;
                if (j==0) dp[i][j]=1;
            }
        }
        for (int i=1; i<n+1; i++){
            for (int j=0; j<maxsum+1; j++){
                int take=0;
                if(arr[i-1]<=j) take=dp[i-1][j-arr[i-1]]%mod;
                int nottake= dp[i-1][j]%mod;
                dp[i][j]=(take+nottake)%mod;
            }
        }
        return dp[n][maxsum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends