class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int cursum=0;
        int maxi=-1e9;
        for (int i=0; i<n; i++){
            if (cursum<0) cursum=0;
            cursum+=nums[i];
            maxi= max(maxi, cursum);
        }
        return maxi;
    }
};