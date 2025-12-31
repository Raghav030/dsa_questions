class Solution {
public:
    void fcombinations(vector<int> candidates, int target, int ind, vector<vector<int>>& ans, vector<int> cur){
        if (ind<0) return;
        if (target==0){
            ans.push_back(cur);
            return;
        }
        if (candidates[ind]<=target){
            cur.push_back(candidates[ind]);
            fcombinations(candidates, target-candidates[ind], ind, ans, cur);
            cur.pop_back();
        }
        fcombinations(candidates, target, ind-1, ans, cur);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        fcombinations(candidates, target, candidates.size()-1, ans, {});
        return ans;
    }
};