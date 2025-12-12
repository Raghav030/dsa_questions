class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> suffix_max_vect(n,0);
        int max_suffix=prices[n-1], max_profit=0, cur_profit=0, cur=0;
        for (int i=n-1; i>0; i--){
            cur= prices[i];
            max_suffix= max(max_suffix, cur);
            suffix_max_vect[i-1]= max_suffix;
        }
        for (int i=0; i<n-1; i++){
            cur_profit= suffix_max_vect[i]-prices[i];
            max_profit= max(max_profit, cur_profit);
        }
        return max_profit;
    }
};