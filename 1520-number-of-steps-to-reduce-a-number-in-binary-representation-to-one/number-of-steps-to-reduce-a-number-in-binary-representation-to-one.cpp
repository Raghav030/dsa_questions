class Solution {
public:
    int numSteps(string s) {
        int n= s.size();
        int i=n-1, ans=0;
        while (i>0){
            if (s[i]=='1'){
                ans+=1;
                while (i>=0 and s[i]=='1'){
                    ans+=1;
                    i-=1;
                }
                if (i>=0) s[i]='1';
            }
            else{
                ans+=1;
                i-=1;
            }
        }
        
        return ans;
    }
};