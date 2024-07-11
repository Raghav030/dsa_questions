class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> st;
        int n= s.size();
        for (int i=0; i<n; i++){
            if (s[i]=='(') st.push(ans.size());
            else if (s[i]==')'){
                int j=st.top();
                st.pop();
                reverse(ans.begin()+j, ans.end());
            }
            else ans+=s[i];
        }
        return ans;
    }
};