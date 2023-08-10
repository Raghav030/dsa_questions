//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.4
    int flcslength(int n, int m, string s1, string s2, vector<vector<int>>& dp){
        if (n==0 or m==0) return 0;
        if (dp[n][m]!=-1) return dp[n][m];
        if (s1[n-1]==s2[m-1]){
            return dp[n][m]= 1+flcslength(n-1, m-1, s1, s2, dp);
        }
        else{
            int take1= flcslength(n-1, m, s1, s2, dp);
            int take2=flcslength(n, m-1, s1, s2, dp);
            return dp[n][m]= max(take1, take2);
        }
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector <vector <int>> dp(n+1, vector<int>(m+1, -1));
        for (int i=0; i<n; i++){
            for (int j=0;j<m; j++){
                if (i==0 or j==0) dp[i][j]=0;
            }
        }
        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    int take1=dp[i-1][j];
                    int take2=dp[i][j-1];
                    dp[i][j]=max(take1, take2);
                }
            }
        }
        return dp[n][m];
        // return flcslength(n, m, s1, s2, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends