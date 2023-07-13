//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int left=0;
        int right=n-1;
        vector <int> ans;
        while (left<right){
            int mid=left+(right-left)/2;
            if (arr[mid]==x){
                left=mid;
                right=mid;
                break;
            }
            if (arr[mid]>x){
                right=mid-1;
            }
            else if (arr[mid]<x){
                    left=mid+1;
            }
        }
        while (arr[left]<=x) left+=1;
        while (arr[right]>=x) right-=1;
        for (int i=0; i<k; i++){
            if (left<n and right<0){
                ans.push_back(arr[left]);
                left+=1;
            }
            if (left>=n and right>=0){
                ans.push_back(arr[right]);
                right-=1;
            }
            if (right>=0 and left<n and arr[left]-x<=x-arr[right]){
                ans.push_back(arr[left]);
                left+=1;
            }
            else if (right>=0 and left<n and arr[left]-x> x-arr[right]){
                ans.push_back(arr[right]);
                right-=1;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends