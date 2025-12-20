class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.size();
        if(t.size() != n) return false;
        vector<int> ascii_arr(26,0);
        for (int i=0; i<n; i++) ascii_arr[s[i]-'a']+=1;
        for (int j=0; j<n; j++){
            if (ascii_arr[t[j]-'a']<=0) return false;
            ascii_arr[t[j]-'a']-=1;
        }
        return true;
    }
};