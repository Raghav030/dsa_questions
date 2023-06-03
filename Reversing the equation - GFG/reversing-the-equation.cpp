//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans;
            stack<int> st;
            for (int i=s.size()-1; i>=0; i--){
                while (i>=0 and 0<=s[i]-'0' and s[i]-'0'<=9){
                    st.push(s[i]);
                    i--;
                }
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                if (i>=0) ans+=s[i];
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends