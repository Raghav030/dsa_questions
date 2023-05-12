//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void fsubsetsum(vector<int> arr, int n, vector <int>& ans, int i, int cursum){
        if (i==n){
            ans.push_back(cursum);
            return;
        }
        fsubsetsum(arr, n, ans, i+1, cursum+arr[i]);
        fsubsetsum(arr, n, ans, i+1, cursum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        fsubsetsum(arr, N, ans, 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends