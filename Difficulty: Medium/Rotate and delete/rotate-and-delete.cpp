//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int m= arr.size();
        // int cur= arr.size()-1;
        // for (int i=1; i<=m/2; i++){
        //     int n= arr.size();
        //     cur = cur-1 >= 0 ? cur-1 : n-1;
        //     if (cur-i+1>=0) arr.erase(arr.begin()+cur-i+1);
        //     else arr.erase(arr.begin());
        // }
        // for (int i=0; i<arr.size(); i++) cout<< arr[i];
        // if (cur< arr.size()-1) return arr[cur+1];
        
        // return arr[0];
        for (int i=1; i<=m/2; i++){
            int n= arr.size();
            int cur=arr[n-1]; 
            arr.pop_back();
            arr.insert(arr.begin(), cur);
            if (n-i+1 >= 0) arr.erase(arr.begin()-i+n);
            else arr.erase(arr.begin());
        }
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends