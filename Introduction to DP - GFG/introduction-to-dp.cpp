//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const long long int mod=1e9+7;
    long long int helper (int n, vector<int>& topd){
        if (n<=1) return topd[n]=n;
        if (topd[n] != -1) return topd[n];
        return topd[n]=(helper(n-1, topd)+helper(n-2, topd))%mod;
    }
    long long int topDown(int n) {
        // code here
        vector<int> topd(n+1,-1);
        return helper(n, topd);
    }
    long long int bottomUp(int n) {
        // code here
        vector<int> bottomu(n+1,-1);
        bottomu[0]=0;
        bottomu[1]=1;
        for (int i=2; i<bottomu.size(); i++){
            bottomu[i]=(bottomu[i-1]+bottomu[i-2])%(mod);
        }
        return bottomu[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends