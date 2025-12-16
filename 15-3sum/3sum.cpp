class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size(), mid, right;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i=0; i<n; i++){
            mid= i+1, right=n-1;
            if (i>0 and nums[i]==nums[i-1]) continue;
            while (mid<right){
                if (nums[i]+nums[mid]+nums[right]==0){
                    ans.push_back({nums[i], nums[mid], nums[right]});
                    int next_mid=mid, next_right=right;
                    while (next_mid<right and nums[next_mid]==nums[mid]){
                        next_mid+=1;
                    }
                    while (next_right>mid and nums[next_right]==nums[right]){
                        next_right-=1;
                    }
                    mid=next_mid;
                    right=next_right;
                }
                if (nums[i]+nums[mid]+nums[right]>0){
                    int next_right =right;
                    while (next_right>mid and nums[next_right]==nums[right]) next_right-=1;
                    right=next_right;
                }
                if (nums[i]+nums[mid]+nums[right]<0){
                    int next_mid=mid;
                    while (next_mid<right and nums[next_mid]==nums[mid]) next_mid+=1;
                    mid=next_mid;
                }
            }
        }
        return ans;
    }
};