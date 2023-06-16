//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int lcs(string str1, string str2, vector<vector<int>>& dp, int i, int j){
    if (i==0 or j==0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (str1[i-1]==str2[j-1]){
        return dp[i][j]=lcs(str1, str2, dp, i-1, j-1)+1;
    }
    else {
        return dp[i][j]= max(lcs(str1, str2, dp, i-1, j), lcs(str1, str2, dp, i, j-1));
    }
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string reversestr = str;
    reverse(reversestr.begin(), reversestr.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (str[i-1]==reversestr[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // int subsequance_len= lcs(str, reversestr, dp, n, n);
    return n-dp[n][n];
} 