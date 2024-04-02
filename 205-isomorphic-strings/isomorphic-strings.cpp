class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int n=s.size();
       if (n != t.size()) return false;
       vector<int> svect(128, -1);
       vector<int> tvect(128, -1);
       for (int i=0; i<n; i++){
        if (svect[s[i]] != -1){
            if (tvect[t[i]]==-1 or t[svect[s[i]]] != t[i]) return false;
        }
        if (tvect[t[i]] != -1){
            if (svect[s[i]]==-1 or s[tvect[t[i]]] != s[i]) return false;
        }
        svect[s[i]]=i;
        
        tvect[t[i]]=i;
       } 
   
       return true;
    }
};