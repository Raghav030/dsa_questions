class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char, int> mpp;
        // int j=0;
        // int n=s.size();
        // int ans=0;
        // for (int i=0; i<n; i++){
        //     if (mpp.find(s[i])!= mpp.end()){
        //         j=max(j, mpp[s[i]]+1);
        //         mpp[s[i]]=i;
        //     }
        //     else{
        //         mpp[s[i]]=i;
        //     }
        //     ans=max(ans, i-j+1);
        // }
        // return ans;
        unordered_map<char, int> asciimap;
        int ans=0;
        int j=0;
        int n= s.size();
        for (int i=0; i<n; i++){
            if (asciimap.find(s[i]) != asciimap.end() and asciimap[s[i]]>0){
                while (s[j]!=s[i]){
                    asciimap[s[j]]-=1;
                    j+=1;
                }
                asciimap[s[j]]-=1;
                j+=1;
            }
            asciimap[s[i]]+=1;
            int cur =i-j+1;
            ans= max(ans, cur);
        }
        return ans;
    }
};