class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(), left=0, right=n-1, mid;
        while (left<right){
            mid= left+ (right-left)/2;
            // cout<<mid;
            if (((mid+1 <n and nums[mid+1] != nums[mid]) and (mid-1>=0 and nums[mid-1] != nums[mid])) or (mid-1<0 and mid+1>=n)) 
                return nums[mid];
            if (mid%2==0){
                if (mid-1>=0 and nums[mid]==nums[mid-1]) right=mid-2;
                else left= mid+1;
            }
            else if (mid%2 !=0){
                if (mid-1>=0 and nums[mid-1] ==nums[mid]) {
                    cout<<mid;
                    left= mid+1;
                }
                else right=mid-1;
            }
        }
        mid= left+ (right-left)/2;
        if ((mid+1 <n and nums[mid+1] != nums[mid]) or (mid-1>=0 and nums[mid-1] != nums[mid]) or (mid-1<0 and mid+1>=n)) 
                return nums[mid];
            return -1;
    }
};