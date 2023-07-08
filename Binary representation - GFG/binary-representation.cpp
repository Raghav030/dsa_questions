//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    string getBinaryRep(int N)
    {
        // Write Your Code here
        string ans="";
        // if (N>=0) ans+='0';
        // else ans+='1';
        for (int i=29; i>=0; i--){
            int p=(N>>i & 1);
            ans+=char('0'+p);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
       
        Solution ob;
        string ans = ob.getBinaryRep(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends