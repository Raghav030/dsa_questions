class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> ans;
        int n= intervals.size();
        int i=0;
        while (i< n){
            int cur_min=intervals[i][0];
            int cur_max= intervals[i][1];
            while (i< n and ((cur_max>= intervals[i][0]))){
                cur_min= min(cur_min, intervals[i][0]);
                cur_max= max(cur_max, intervals[i][1]);
                i+=1;
            }
            ans.push_back({cur_min, cur_max});
        }
        return ans;
    }
};