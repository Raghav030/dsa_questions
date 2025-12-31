class Solution {
public:
    void fparenthesis (int opening_brackets, int closing_brackets, string cur, vector<string>& ans){
        if (opening_brackets==0 and closing_brackets==0) {
            ans.push_back(cur);
            return;
        }
        if (opening_brackets>0){
            cur= cur+'(';
            fparenthesis(opening_brackets-1, closing_brackets, cur, ans);
            cur.erase(cur.size()-1);
        }
        if (closing_brackets>opening_brackets){
            cur=cur+')';
            fparenthesis(opening_brackets, closing_brackets-1, cur, ans);
            cur.erase(cur.size()-1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fparenthesis(n, n, "", ans);
        return ans;
    }
};