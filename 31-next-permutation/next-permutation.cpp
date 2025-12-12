class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), cur_left=-1, cur_right=-1;
        for (int i=1; i<n; i++){
            if (nums[i]>nums[i-1]){
                cur_left=i-1;
                cur_right=i;
            }
            else if (cur_left != -1 and cur_right != -1 and nums[i]>nums[cur_left] ){
                cur_right=i;
            }
        }
        if (cur_left ==-1 and cur_right==-1) cur_right=n-1;
        else{
            swap(nums[cur_left], nums[cur_right]);
        }
        cout<<cur_left;
        for (int i=cur_left+1; i<(cur_left+n+1)/2; i++){
            swap(nums[i], nums[n-(i-cur_left)]);
        }
    }
};