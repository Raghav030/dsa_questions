//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code
        string scopy=s;
        int n=s.size();
        for(int i=0; i<n; i++){
            if (scopy[i]!='?'){
                if (scopy[n-i-1]!='?' and scopy[n-i-1]!=scopy[i]) return -1;
                scopy[n-i-1]=scopy[i];
            }
        }
        int ans=0;
        char sprevious='?';
        for (int i=0; i<n; i++){
            if (scopy[i]!='?'){
                if (sprevious=='?') sprevious=scopy[i];
                // return 2;
                ans=ans+abs(scopy[i]-sprevious);
                sprevious=scopy[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends