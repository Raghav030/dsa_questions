//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    // long long get_index (vector<long long>& arr, int l, int r, int num){
    //     if ()
    // }
    long long minCost(vector<long long>& arr) {
        // Your code here
        long long ans=0, n= arr.size();
        // if (arr.size()<2) return 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i=0; i<n; i++) pq.push(arr[i]);
        while (pq.size()>1){
            int num1= pq.top();
            pq.pop();
            int num2= pq.top();
            pq.pop();
            int cur= num1+num2;
            ans+=cur;
            pq.push(cur);
        }
        // ans= ans;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends