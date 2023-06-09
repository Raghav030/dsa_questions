//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void permutations(string& s, set<string>& ans, int i){
	    ans.insert(s);
	    int j=i;
	    while (j<s.size() and i<s.size()){
	        swap(s[i], s[j]);
	        permutations(s, ans, i+1);
	        swap(s[i],s[j]);
	        j+=1;
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(), S.end());
		    set<string> ans;
		    vector<string> vect;
		  //  while (!ans.empty()){
		  //      vect.push_back(ans.begin());
		  //      ans.erase(ans.begin());
		  //  }
		    permutations(S, ans, 0);
		  //  sort(ans.begin(), ans.end());
		  for (auto it = ans.begin(); it != ans.end(); ++it) {
            vect.push_back(*it);
    }
		    return vect;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends