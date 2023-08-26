//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n= s.size();
    int count =0;
    unordered_map <char, int> mpp;
    int j=0;
    int ans=-1;
    for (int i=0; i<n; i++){
        if (mpp.find(s[i]) != mpp.end()){
            mpp[s[i]]+=1;
            
        }
        else {
            mpp[s[i]]=1;
            count+=1;
            if (count > k){
                while (j<i){
                    mpp[s[j]]-=1;
                    if (mpp[s[j]]==0){
                        mpp.erase(s[j]);                    
                        count-=1;
                    }
                    j+=1;
                    if (count<=k ) break;
                }
            }
        }
        if (count==k) ans =max(ans, i-j+1);
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends