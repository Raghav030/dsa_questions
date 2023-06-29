//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long int fpower(int mid, int n, int m){
	    long long ans=1;
	    for (int i=0; i<n; i++){
	        ans=(ans*mid);
	        if (ans> m) return m+1;
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    long long int right=m;
	   // if (right> 2000) right/=2;
	    long long int left =1;
	    while (left<=right){
	        int mid = left +(right-left)/2;
	        long long int power_num=fpower(mid, n, m);
	        if (power_num == m) return mid;
	        if (power_num> m) right = mid-1;
	        if (power_num< m) left=mid+1;
	    }
	    return -1;
	    
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends