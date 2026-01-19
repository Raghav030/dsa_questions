class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n= nums.size(), left_num=0, cur_sum=0, j=0, right_num=0, ans=0;
        for (int i=0; i<n; i++){
            cur_sum+=nums[i];
            if (cur_sum>goal){
                // if (nums[j]==0) left_zeroes+=1;
                while (nums[j] != 1){
                    j+=1;
                    left_num+=1;
                }
                left_num+=1;
                j+=1;
                cur_sum-=1;
                // cout<<344;
                cout<<left_num<< right_num<< endl;
                if (goal>0)ans = ans + left_num* right_num;
                else ans= ans + left_num* right_num/2;
                left_num=0;
                right_num= goal>0 ?1:0;
            }
            else if (cur_sum==goal){
                right_num+=1;
                // cout<<right_num<<endl;
            }
            // if (goal== cur_sum and nums[i]==1)

        }
        if (cur_sum== goal){
            while (j<n and nums[j] != 1){
                j+=1;
                left_num+=1;
            }
            left_num+=1;
            cout<<left_num<< right_num<< endl;
            if (goal>0) ans= ans+ left_num* right_num;
            else ans= ans + left_num* right_num/2;
        }
        return ans;
    }
};