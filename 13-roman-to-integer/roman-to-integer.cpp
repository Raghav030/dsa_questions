class Solution {
public:
    int romanToInt(string s) {
        int n= s.size(), ans=0;
        for (int i=0; i<n; i++){
            if (s[i]=='I') ans+=1;
            // else if (s[i]=='V') ans+=5;
            // else if (s[i]=='L') ans+=50;
            // else if (s[i]=='L') ans+=50;
            // else if (s[i]=='D') ans+=500;
            // else if (s[i]=='M') ans+=1000;
            // else if (s[i]=='I'){
            //     if (i+1<n and s[i+1])
            // }
            else if (s[i]=='X' and i>0 and s[i-1]=='I') ans+=8;
            else if (s[i]=='V' and i>0 and s[i-1]=='I') ans+=3;
            else if (s[i]=='L' and i>0 and s[i-1]=='X') ans+=30;
            else if (s[i]=='C' and i>0 and s[i-1]=='X') ans+=80;
            else if (s[i]=='D' and i>0 and s[i-1]=='C') ans+=300;
            else if (s[i]=='M' and i>0 and s[i-1]=='C') ans+=800;
            else if (s[i]=='X') ans+=10;
            else if (s[i]=='C') ans+=100;
            else if (s[i]=='L') ans+=50;
            else if (s[i]=='V') ans+=5;
            else if (s[i]=='D') ans+=500;
            else if (s[i]=='M') ans+=1000;
        }
        return ans;
    }
};