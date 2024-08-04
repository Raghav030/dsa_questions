class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans=0, mod=1e9+7;
        for (int i=0; i<n; i++){
            int num=0, cur=0;
            for (int j=0; j<=i; j++) cur+=nums[j];
            pq.push(cur);
            for (int j=i+1; j<n; j++){
                // if (j-num+1 > i){
                //     cur-=nums[num];
                //     num+=1;
                // }
                cur-=nums[num];
                num+=1;
                cur+=nums[j];
                pq.push(cur);
            }
            // pq.push()
        }
        for (int i=1; i<left; i++){
            // cout<<pq.top();
            pq.pop();
        }
        for (int i=left; i<=right; i++){
            ans=(ans+pq.top()%(mod))%mod;
            cout<<ans;
            pq.pop();
        }
        return ans;
    }
};