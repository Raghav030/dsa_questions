//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map <int, int> mpp;
        int n= nums.size();
        vector <int> ans;
        priority_queue <pair<int, int>, vector <pair<int,int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; i++){
            mpp[nums[i]]+=1;
        }
        for (auto t: mpp){
            pq.push({t.second, t.first});
            if (pq.size()>k){
                pq.pop();
            }
        }
        while (!pq.empty()){
            auto t= pq.top();
            ans.push_back(t.second);
            pq.pop();
        }
        reverse(ans.begin(), ans. end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends