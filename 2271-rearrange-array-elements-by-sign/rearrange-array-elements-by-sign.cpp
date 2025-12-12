class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size(), pos_ind=0, neg_ind=1;
        vector<int> rearranged_nums(n);
        for (int i=0; i<n; i++){
            if (nums[i]>0){
                rearranged_nums[pos_ind]=nums[i];
                pos_ind+=2;
            }
            else{
                rearranged_nums[neg_ind]=nums[i];
                neg_ind+=2;
            }
        }
        return rearranged_nums;
    }
};