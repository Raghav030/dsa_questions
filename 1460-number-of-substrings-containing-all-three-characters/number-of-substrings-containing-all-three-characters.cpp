class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size(), ans=0, cur_start=0, j=0;
        unordered_map<char, int> mpp;
        for (int i=0; i<n; i++){
            if ((s[i]=='a' or s[i]=='b' or s[i]=='c')){
                mpp[s[i]]+=1;
            }
            while (mpp.size()==3){
                ans= ans+ (n-i);
                cout<<i;
                // mpp.erase(s[j]);
                mpp[s[j]]-=1;
                if (mpp[s[j]]==0) mpp.erase(s[j]);
                j+=1;
            }
        }
        return ans;
    }
};