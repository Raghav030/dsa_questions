class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // unordered_map <char, int> mpp;
        vector<int> ascii_nums_st(256,' ');
        vector<int> ascii_nums_ts(256,' ');
        char NUL= '\0';
        int n= s.size(), m=t.size();
        // if (n != t.size()) return false;
        for (int i=0; i<max(n,m); i++){
            // mpp[s[i]]+=1;
            if (i<n and ascii_nums_st[s[i]-NUL]==' ') ascii_nums_st[s[i]-NUL]=t[i];
            else if (i<n and ascii_nums_st[s[i]-NUL] != t[i]) {
                cout<< t[i]<< s[i];
                return false;
            }
            if (i< m and ascii_nums_ts[t[i]-NUL]==' ') ascii_nums_ts[t[i]-NUL]=s[i];
            else if (i<m and ascii_nums_ts[t[i]-NUL] != s[i]) {
                cout<<s[i];
                return false;
            }

        }
        // for (int i=0; i<t.size(); i++){
        //     if (mpp.find(t[i])==mpp.end() or mpp[t[i]]==0) return false;
        //     mpp[t[i]]-=1;
        // }
        // if (mpp.size()>0) return false;
        return true;
    }
};