class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n= nums.size();
        for (int i=0; i<n; i++){
            mpp[nums[i]]=i;
        }
        for (int i=0; i<n; i++){
            int cur_element= nums[i];
            int remaining_element= target- nums[i];
            // mpp.erase(mpp[nums[i]]);
            if (mpp.find(remaining_element) != mpp.end() and mpp[remaining_element]!=i) return {i, mpp[remaining_element]};
        }
        return {};
    }
};