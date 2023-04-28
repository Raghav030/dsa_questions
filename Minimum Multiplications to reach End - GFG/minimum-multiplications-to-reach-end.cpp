//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue <pair<int,int>> q;
        vector<int> vis(100000, 0);
        q.push({0,start});
        vis[start]=1;
        while (!q.empty()){
            int node=q.front().second;
            int distance=q.front().first;
            q.pop();
            if (node==end) return distance;
            for (int i=0; i<arr.size(); i++){
                if (vis[(node*arr[i])%100000] != 1){
                    q.push({distance+1, node*arr[i]%100000});
                    vis[(node*arr[i])%100000]=1;
                    if (node*arr[i]%100000==end) return distance+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends