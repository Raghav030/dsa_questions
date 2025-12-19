class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size(), left=0, right=n-1, mid;
        while (left<right){
            mid= left + (right-left)/2;
            if (nums[mid]== target) return mid;
            if (nums[mid]<target) left=mid+1;
            else right=mid;
        }
        if (left==n-1 and nums[left]< target) left+=1;
        return left;

    }
};