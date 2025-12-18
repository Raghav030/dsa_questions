class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1, mid;
        while (left<right){
            mid= (left+right)/2;
            if (nums[mid]==target) return mid;
            cout<<mid;
            if (nums[mid]<target){
                // if (nums[left]>targ)
                // left=mid+1;
                // if
                // if (nums[right] >target) left=mid+1;
                // else if (nums[right]<target) right=mid-1;
                // else if (nums[right]==target) return right;
                if (nums[mid]<nums[right] and target>nums[right]) right=mid-1;
                else if (nums[mid]<nums[right] and target<=nums[right]) left= mid+1;
                else if (nums[mid]>=nums[right]) left=mid+1;

            }
            if (nums[mid]>target){
                // if(nums[left]== target) return left;
                // else if (nums[left]>target) left=mid+1;
                // else if (nums[left]<target) right=mid-1;
                if (nums[mid]<nums[left]) right=mid-1;
                else if (nums[left]<=nums[mid] and target <nums[left]) left=mid+1;
                else if (nums[left]<=nums[mid] and nums[left]<=target) right=mid-1;
            }
        }
        if (left>=0 and nums[left]==target) return left;
        return -1;
    }
};