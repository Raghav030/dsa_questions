class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int orderstarttime=0, n= customers.size();
        long long twaitingtime=0;
        for (int i=0; i<n; i++){
            orderstarttime=max(orderstarttime, customers[i][0]);
            // cout<<orderstarttime;
            orderstarttime+=customers[i][1];
            int waitingtime= orderstarttime-customers[i][0];
            cout<<waitingtime;
            twaitingtime=twaitingtime+ (max(waitingtime, 0));
        }
        double ans= 0.0000;
        ans=double(twaitingtime)/double(n);
        return ans;
        // return double(1.0 * double(twaitingtime/n));
    }
};