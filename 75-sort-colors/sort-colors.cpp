class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int nzero=0;
        int ntwo=n-1;
        while (ntwo>=0 and nums[ntwo]==2) ntwo-=1;
        for (int i=0; i<=ntwo; i++){
            if (nums[i]==0) {
                swap(nums[nzero], nums[i]);
                nzero+=1;
            }
            if (nums[i]==2){
                swap(nums[i], nums[ntwo]);
                ntwo-=1;
                i-=1;
            }
        }
    }
};