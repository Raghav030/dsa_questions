class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> futurevect(n, -1);
        int ans=0;
        for (int i= n-1; i>=0; i--){
            int curprice= prices[i];
            int futuremaxprice= i!= n-1 ? futurevect[i+1]:-1;
            futurevect[i]=max(curprice, futuremaxprice);
        }
        for (int i=0; i<n; i++){
            int curprofit= futurevect[i]-prices[i];
            ans= max(ans, curprofit);
        }
        return ans;
    }
};