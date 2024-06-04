class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size(), flag=0, ans=0;
        vector<int> vectlower(26,0), vectupper(26,0);
        for (int i=0; i<n; i++){
            if (s[i]>='a'){
                vectlower[s[i]-'a']+=1;
                if (vectlower[s[i]-'a']%2==0) ans+=2;
                // if (vectlower[s[i]-'a']%2==1 and flag==0){
                //     ans+=1;
                //     flag=1;
                // }
            }
            else {
                vectupper[s[i]-'A']+=1;
                if (vectupper[s[i]-'A']%2==0) ans+=2;
                // if (vectupper[s[i]-'A']%2==1 and flag==0){
                //     ans+=1;
                //     flag=1;
                // }
            }
        }
        for (int i=0; i<26; i++){
            if (vectupper[i]%2==1 or vectlower[i]%2==1){
                ans+=1;
                break;
            }
        }
        return ans;
    }
};