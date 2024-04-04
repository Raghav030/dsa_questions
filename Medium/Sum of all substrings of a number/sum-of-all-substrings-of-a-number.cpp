//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long ans=0;
        int n= s.size();
        long long cur=0;
        for (int i=0; i<n; i++){
            cur= (cur*10%((1000000000+7))+ (s[i]-'0')*(i+1))%((1000000000+7));
            ans=ans+cur;
            ans= ans%((1000000000+7));
        }
        return ans%(1000000000+7);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends