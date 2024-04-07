class Solution {
public:
    bool checkValidString(string s) {
        int n= s.size();
        int pos=0, neg=0, temp=0;
        for (int i=0; i<n; i++){
            if (s[i]=='(') temp+=1;
            if (s[i]==')') temp-=1;
            if (s[i]=='*' and temp>=0) neg+=1; 
            if (temp<0){
                if (neg<abs(temp)) return false;
                neg=neg-abs(temp);
                temp=0;
            }
        }
        temp=0;
        for (int i=n-1; i>=0; i--){
            if (s[i]=='(') temp+=1;
            if (s[i]==')') temp-=1;
            if (s[i]=='*' and temp<=0) pos+=1;
            if (temp>0){
                if (pos<temp) return false;
                pos-=temp;
                temp=0;
            }
        }
        // if (temp>0) return false;
        return true;
    }
};