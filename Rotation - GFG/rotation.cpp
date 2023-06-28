//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int mini=1e9;
	    int ind;
	    int left=0;
	    int right=n-1;
	    while (left<=right){
	        int mid= left+ (right-left)/2;
	        if (arr[mid]==arr[left] and arr[mid]==arr[right]){
	            if (mini>arr[right]){
	                mini=arr[right];
	                ind=right;
	            }
	            left+=1;
	            right-=1;
	            continue;
	        }
	        if (arr[left]<=arr[mid]){
	            if (mini>arr[left]){
	                mini=arr[left];
	                ind=left;
	            }
	            left=mid+1;
	        }
	        else if (arr[mid]<=arr[right]){
	            if (arr[mid]<mini){
	                mini=arr[mid];
	                ind =mid;
	            }
	            right=mid-1;
	        }
	    }
	    return ind;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends