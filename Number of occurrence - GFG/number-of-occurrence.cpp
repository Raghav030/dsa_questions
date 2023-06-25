//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int fstart_ind(int arr[], int n, int x){
	    int left=0;
	    int right=n-1;
	    int mid;
	    while (left <=right){
	        mid=(left+right)/2;
	        if (arr[mid]>=x) right=mid-1;
	        else left=mid+1;
	    }
	    return left;
	}
	int fend_ind(int arr[], int n, int x){
	    int left=0;
	    int right=n-1;
	    int mid;
	    while (left <=right){
	        mid=(left+right)/2;
	        if (arr[mid]<=x) left=mid+1;
	        else right=right-1;
	    }
	    return left;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int start_index= fstart_ind(arr, n, x);
	    int end_index = fend_ind(arr, n, x);
	    if (start_index==-1 or arr[start_index]!=x) return 0;
	    return (end_index-start_index);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends