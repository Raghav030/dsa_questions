class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n= tickets.size();
        int ans= (tickets[k]-1)*(n)+k+1;

        for (int i=0; i<n; i++){
            ans= (i<k and tickets[i]<tickets[k])? ans+tickets[i]-tickets[k]: ans;
            ans= (i>k and tickets[i]<tickets[k]-1)? ans+tickets[i]-tickets[k]+1: ans;

        }
        return ans;
    }

};