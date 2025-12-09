class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int num_red=0, num_white=0, num_blue=0;
        for (int i=0; i<n; i++){
            // if (nums[i]==0){
            //     nums[num_red]=0;
            // }
            if (nums[i]==0) num_red+=1;
            if (nums[i]==1) num_white+=1;
            if (nums[i]==2) num_blue+=1;
        }
        for (int i=0; i<n; i++){
            if (i<num_red) nums[i]=0;
            if (i>=num_red and i<num_red+num_white) nums[i]=1;
            if (i>= num_red+num_white) nums[i]=2;
        }

    }
};