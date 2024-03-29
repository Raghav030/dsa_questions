class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n= nums.size();
        int i=0, j=0, cur=0, maxi=nums[0];
        for (int k=0; k<n; k++) maxi=max(maxi, nums[k]); 
        while (i<n){
            if (nums[i]== maxi) cur+=1;
            if (cur==k){
                long long l=1, r=0;
                while (nums[j] != maxi){
                    j+=1;
                    l+=1;
                }
                r=n-i;
                ans= ans+1LL*( l)*(1LL*r); 
                j+=1;
                cur-=1;
            }
            i+=1;
        }
        return ans;
    }
};