class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n= nums.size(), prefix_sum=0, total_sum=0,left_sum=0, suffix_sum=0, ans=0;
        for (int i=0; i<n-1; i++){
            suffix_sum+=nums[i];
            mpp[suffix_sum]+=1;
        }
        mpp[0]+=1;
        total_sum= suffix_sum+nums[n-1];
        left_sum= total_sum-k;
        suffix_sum=0;
        for(int i=n-1; i>=0; i--){
            prefix_sum=left_sum-suffix_sum;
            cout<<left_sum<<prefix_sum;
            if (mpp.find(prefix_sum) != mpp.end()) ans+=mpp[prefix_sum];
            suffix_sum+=nums[i];
            mpp[(total_sum-suffix_sum)]-=1;
            // left_sum=left_sum-suffix_sum;
        }
        return ans;
    }
};

//k=2 
//=> prefix_sum+suffix_sum=3
//ans = 1
// 1 2 -2 4  
/*
{
    (prefix_sum)->(frequency(prefix_sum))
    1->1
    --     3->1
    --     5->1

}


*/