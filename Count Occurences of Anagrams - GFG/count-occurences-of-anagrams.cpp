//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector <int> ascii(26, 0);
	    vector <int> as(26, 0);
	    int n=pat.size();
	    int m=txt.size();
	    int cur_ele=0;
	    int ans=0;
	    int j=0;
	    for (int i=0; i<n; i++){
	        ascii[pat[i]-'a']+=1;
	    }
	    for (int i=0; i<m; i++){
    	    int flag=1;
	        if (i<n){
	            if (ascii[txt[i]-'a'] !=0 ){
	                if (ascii[txt[i]-'a']>0){
	                    
	                    cur_ele+=1;
	                }
	                as[txt[i]-'a']+=1;
	            }
	        }
	        else{
	            if (ascii[txt[i]-'a'] >0){
	                as[txt[i]-'a']+=1;
	                cur_ele+=1;
	            }
	            if (ascii[txt[j]-'a']>0){ 
	                as[txt[j]-'a']-=1;
	            }
	            j+=1;
	        }
	       // if (cur_ele==n) ans+=1;
	       for (int j=0; j<26; j++){
	           if (as[j]!=ascii[j]) flag=0;
	       }
	       if (flag==1) ans+=1;
	        
	    }
	   // if (cur_ele==n) ans+=1;
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends