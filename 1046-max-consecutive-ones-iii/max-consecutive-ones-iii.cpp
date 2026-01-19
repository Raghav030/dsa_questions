class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size(), ans=0, last_zero_ind=-1, cur_start=0;
        for (int i=0; i<n; i++){
            if (nums[i]==0) {
                if (k>0){
                    k-=1;
                }
                else if (k==0){
                    while (cur_start<n and nums[cur_start] != 0){
                        cur_start+=1;
                    }
                    cur_start+=1;
                    // k+=1;
                }
                // cur_start= last_zero_ind+1;
                // last_zero_ind=i;
            }
            int cur_length= i- cur_start+1;
            ans= max(ans, cur_length);

        }
        return ans;
    }
};