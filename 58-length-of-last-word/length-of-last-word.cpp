class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        for (int i=n-1; i>=0; i--){
            if (i==n-1){
                while (i>=0 and s[i]==' ') {
                    i-=1;
                    n-=1;
                }
                if(i==-1) return 0;
            }
            if (s[i]==' ') return n-i-1;
            if (i==0) return n;
        }
        return 0;
    }
};