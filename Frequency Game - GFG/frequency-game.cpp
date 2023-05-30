//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int, int> us;
        for (int i=0; i<n; i++){
            us[arr[i]]+=1;
        }
        int ans=0;
        int temp=n;
        while (!us.empty()){
            auto it= *(us.begin());
            if (it.second <temp){
                ans=it.first;
                temp=it.second;
            }
            else if (it.second == temp){
                if (it.first> ans){
                    ans=it.first;
                }
            }
            us.erase(us.begin());
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends