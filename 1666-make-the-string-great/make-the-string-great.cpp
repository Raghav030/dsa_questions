class Solution {
public:
    string makeGood(string s) {
        // string a="ssZDDVDVF";
        int n=s.size(), i=0;
        while (n>0 and i<n-1){
            if (s[i]+32==s[i+1] || s[i+1]+32== s[i]){
                s.erase(i,2);
                if (i>0) i-=1;
            }
            else i+=1;
        }
        return s;
    }
};