//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n= nums.size();
        vector <int> ans;
        // for (int i=0; i<n; i++){
        //     if (n-nums[i]>nums[i]) continue;
        //     if  (nums[nums[i]-1]!=nums[i] ){
        //         swap(nums[nums[i]-1], nums[i]);
        //         i--;
        //     }
        //     else if (nums[n- nums[i]]!= n-nums[i] ){
        //         cout<< i;
        //         swap(nums[n-nums[i]], nums[i]);
        //         i--;
        //     }
        // }
        // for (int i=0; i<n; i++){
        //     if (i<n/2){
        //         if (i!= nums[i]-1) ans.push_back(nums[i]);
        //     }
        //     else if (i>=n/2){
        //         if (n-i!= nums[i]){
        //             ans.push_back(nums[i]);
        //         }
        //     }
        // }
        // return nums;
        unordered_map <int, int> mpp;
        for (int i=0; i<n; i++){
            mpp[nums[i]]+=1;
        }
        for (auto t: mpp){
            if (t.second==1) ans.push_back(t.first);
        }
        if (ans[0]> ans[1]) swap(ans[0], ans[1]);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends