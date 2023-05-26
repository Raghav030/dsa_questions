//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        // code here
        vector<int> prev(n+1, 0);
        prev[0]=1;
        vector<int> vect(n+1, 0);
        vect[0]=1;
        double temp= 1.0/x;
        int mod=1e9+7;
        int root= pow(n, temp);
        for (int i=1; i<=root; i++){
            for (int j=1; j<n+1; j++){
                int take=0;
                if (j>= pow(i, x)) take= prev[j-pow(i, x)]%mod;
                int nottake = prev[j]%mod;
                vect[j]=(take+nottake)%mod;
            }
            prev=vect;
        }
        return vect[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends