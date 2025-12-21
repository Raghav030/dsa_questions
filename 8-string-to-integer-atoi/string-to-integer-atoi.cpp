class Solution {
public:
    int myAtoi(string s) {
        int n= s.size(), sign=0, num_start=-1;
        long long ans=0;
        // INT_MAX= 
        for (int i=0; i<n; i++){
            cout<<i;
            if ((((s[i]<'0' or s[i]>'9')) and s[i]!='-' and s[i]!= ' ' and s[i]!= '+')) break;
            // or ((s[i]<'0' or s[i]>'9') and ((s[i]=='-' and sign !=0) or (s[i]=='+' and sign !=0)))
            if (sign!=0 and  (s[i]<'0' or s[i]>'9')) break;
            if (s[i]=='-') sign= -1;
            if (s[i]=='+') sign= 1;
            if (s[i]>='0' and s[i]<='9') {
                if (sign==0) sign=1;
                num_start=1;
                if (1LL*(ans*10)+ 1ll*(s[i]-'0')>=INT_MAX) {
                    if (1LL*(ans*10)+ 1ll*(s[i]-'0')>INT_MAX and sign==-1) return INT_MIN;
                    if (sign==1) return  INT_MAX;
                    ans=INT_MAX;
                    continue;
                }
                ans= ans*10 + (s[i]-'0');
            }
        }
        ans*=sign;
        return int(ans);

    }
};