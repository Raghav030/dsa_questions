//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue <char> q;
		  //  set <int> st;
		    vector <int> ascii(26, 0);
		    int n=s.size();
		    string ans="";
		    for (int i=0; i<n; i++){
		        if (ascii[s[i]-'a']==0){
		            q.push(s[i]);
		            ascii[s[i]-'a']+=1;
		        }
		        else{
		            ascii[s[i]-'a']+=1;
		        }
	            if (!q.empty()) {
	                while (!q.empty() and ascii[q.front()-'a']>1) q.pop();
	            }
	            if (q.empty()) ans+='#';
	            else ans+=q.front();
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends