//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void sieveoferanthoese(int n, vector<int> vect, vector<int>& ans){
        for (int i=2; i<n; i++){
            if (vect[i]==0){
                ans.push_back(i);
                for (int j=i; j<n; j+=i){
                    vect[j]=1;
                }
            }
        }
    }
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> primes;
        vector<int> vect(n+1, 0);
        sieveoferanthoese(n+1, vect, primes);
        vector<int> ans(n+1, 0);
        ans[1]=1;
        for  (int i=2; i<n+1; i++){
            for (int j=0; j<primes.size(); j++){
                if (i%primes[j]==0) {
                    ans[i]=primes[j];
                    break;
                }
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
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends