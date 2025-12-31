class Solution {
public:
    void fsubsets(int i, vector<vector<int>>& ans, vector<int> cur, vector<int> nums){
        if (i==nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        fsubsets(i+1, ans, cur, nums);
        cur.pop_back();
        fsubsets(i+1, ans, cur, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        fsubsets(0, ans, {}, nums);
        return ans;
    }
};