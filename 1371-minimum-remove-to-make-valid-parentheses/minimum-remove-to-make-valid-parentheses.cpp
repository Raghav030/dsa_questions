class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int temp=0;
        int n=s.size();
        for (int i=0; i<n; i++){
            if (s[i]=='(') temp+=1;
            if (s[i]==')') temp-=1;
            if (temp<0){
                s.erase(i,1);
                temp+=1;
                i-=1;
            }
        }
        int i=n-1;
        while (temp>0){
            if (s[i]=='('){
                s.erase(i, 1);
                temp-=1;
            }
            i-=1;
        }
        return s;
    }
};