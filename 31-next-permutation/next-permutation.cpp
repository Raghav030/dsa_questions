class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int lastasc=-1;
        int nextbig=-1;
        for (int i=0; i<n; i++){
            if (i<n-1 and nums[i+1]>nums[i]){ 
                lastasc=i;
                nextbig= i+1;
            }
            if (lastasc != -1 and nums[lastasc] < nums[i] and nums[i]<nums[nextbig]) nextbig=i;
        }
        if (lastasc != -1) swap(nums[lastasc], nums[nextbig]);
        sort(nums.begin()+lastasc+1, nums.end());
    }
};