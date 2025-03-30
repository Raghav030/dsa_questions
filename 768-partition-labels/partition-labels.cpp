class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastind(26, -1), ans;
        int n=s.size();
        for (int i=0; i<n; i++){
            lastind[(s[i]-'a')]=i;
        }
        int cur_limit=s.size()==0? 0: lastind[s[0]-'a'], j=-1;
        for (int i=0; i<n; i++){
            cur_limit = cur_limit< lastind[s[i]-'a']? lastind[s[i]-'a']: cur_limit;
            if (cur_limit== i){ 
                ans.push_back((i-j));
                j=i;
            }
        }
        return ans;
    }
};