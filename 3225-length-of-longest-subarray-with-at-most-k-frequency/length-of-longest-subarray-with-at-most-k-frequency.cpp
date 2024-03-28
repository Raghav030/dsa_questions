class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n= nums.size();
        if (k==0) return 0;
        int ans=0;
        int j=0;
        for (int i=0; i<n; i++){
            mpp[nums[i]]+=1;
            while (mpp[nums[i]]>k){
                mpp[nums[j]]-=1;
                j+=1;
            }
            int cur= i-j+1;
            ans=max(cur, ans);
        }
        return ans;
    }
};