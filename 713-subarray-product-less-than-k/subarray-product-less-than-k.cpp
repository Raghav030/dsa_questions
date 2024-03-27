class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j=-1;
        int i=0;
        int n= nums.size();
        int ans=0, cur=1;
        while (i<n){
            cur*=nums[i];
            if (cur<k) ans= ans+ (i-j);
            else{
                while(j<i and cur>=k){
                    j+=1;
                    cur/=nums[j];
                }
                ans= ans+ (i-j);
            }
            i+=1;

        }
        return ans;
    }
};