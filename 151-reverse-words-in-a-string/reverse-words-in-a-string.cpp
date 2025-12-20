class Solution {
public:
    string reverseWords(string s) {
        int n= s.size(), cur_word_end, i=n-1;
        string ans="";
        while (i>=0){
            // if (s[i]!=' ') cur_word_end =i-1;
            if (s[i]!=' '){
                cur_word_end=i;
                while (i>=0 and s[i] != ' '){
                    i-=1;
                }
                if (ans.size()>0) ans+=' ';
                for (int j=i+1; j<=cur_word_end; j++){
                    ans+=s[j];
                }
            }
            i-=1;
        }
        return ans;
    }
};