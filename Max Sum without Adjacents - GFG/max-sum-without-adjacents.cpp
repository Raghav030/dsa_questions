//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	void fmsum(int arr[], int n, int& temp, int& ans, int i, vector <int> maxi){
// 	    if (i>=n){
// 	        if (temp>ans) ans =temp;
// 	       // temp=0;
// 	        return;
// 	    }
// 	    if (maxi[i]!=-1){
// 	        temp+=maxi[i];
// 	        if (temp> ans) ans=temp;
// 	        temp-=maxi[i];
// 	        return;
// 	    }
// 	    temp+=arr[i];
// 	    fmsum(arr, n, temp, ans, i+2);
// 	   // fmsum(arr, n, temp, ans, i+3);
// 	    temp-=arr[i];
// 	    i+=1;
// 	    if (i<n){
// 	       // temp+=arr[i];
// 	        fmsum(arr, n, temp, ans, i);
// 	       // temp-=arr[i];
	       
// 	    }
// 	   // maxi[i-1]
	    
// 	}
	int findMaxSum(int *arr, int n) {
	    // code here
	   // int ans=0;
	   // int temp=0;
	   // int i=0;
	   // vector<int> maxi(n,-1);
	   // fmsum(arr, n, temp, ans, i, maxi);
	   // return ans;
	   vector <int> sums(n, -1);
	   sums[0]=arr[0];
	   if (n==1) return arr[0];
	   sums[1]=arr[1];
	   if (n==2) return max(arr[1], arr[0]);
	   sums[2]=arr[0]+arr[2];
	   if (n==3) return max(arr[0]+arr[2], arr[1]);
	   for (int i=3; i<sums.size(); i++){
	       sums[i]=arr[i]+max(sums[i-2], sums[i-3]);
	   }
	   return max(sums[n-2], sums[n-1]); 
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends