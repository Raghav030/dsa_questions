class Solution {
public:
    int beautySum(string s) {
        int n= s.size(), ans=0, cur_frequency=0;
        vector<int> ascii_arr(26,0);
        for (int i=0; i<n; i++){
            for (int k=0; k<26; k++) ascii_arr[k]=0;
            for (int j=i; j<n; j++){
                ascii_arr[s[j]-'a']+=1;
                int cur_max=0, cur_min=1e9;
                for (int k=0; k<26; k++){
                    int cur= ascii_arr[k];
                    cur_max= max(cur_max, cur);
                    if (cur>0) cur_min= min(cur_min, cur);
                }
                cout<<cur_max;
                ans= ans+ (cur_max-cur_min);
            }
        }
        return ans;
    }
};