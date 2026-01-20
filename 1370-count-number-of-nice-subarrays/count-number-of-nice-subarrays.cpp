class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size(), ans=0, cur_odd_nums=0, j=0;
        // get numSubaArrays whith odd numbers<=k
        if (k==0) return ans;
        for (int i=0; i<n; i++){
            if (nums[i]%2==1) cur_odd_nums+=1;
            if (cur_odd_nums>k){
                while (nums[j]%2 != 1) j+=1;
                cur_odd_nums-=1;
                j+=1;
            }
            if (cur_odd_nums<=k){
                ans= ans+ i-j+1;
            }
        }
        //get subArrays with od numbers<=k-1
        cur_odd_nums =0; 
        j=0;
        cout<<ans<< endl;
        // if (k-1 <0 ) return ans;
        for (int i=0; i<n; i++){
            if (nums[i]%2==1) cur_odd_nums +=1;
            if (cur_odd_nums> k-1){
                while (nums[j]%2 != 1) j+=1;
                cur_odd_nums-=1;
                j+=1;
            }
            if (cur_odd_nums <= k-1){
                ans = ans -(i-j+1);
                cout<< ans<<endl;
            }
        }
        return ans;
    }
};