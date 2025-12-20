class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size(), cur_open_parentheses=0;
        string ans="";
        for (int i=0; i<n; i++){
            if (cur_open_parentheses==0 and s[i]=='(') cur_open_parentheses+=1;
            else if (cur_open_parentheses==1 and s[i]==')') cur_open_parentheses-=1;
            else{
                ans+=s[i];
                if (s[i]=='(') cur_open_parentheses+=1;
                else cur_open_parentheses-=1;
            }
        }
        return ans;
    }
};