class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n= words.size();
        vector<int> ascii1(26,0);
        vector<string> ans;
        for (int i=0; i<n; i++){
            vector<int> ascii2(26,0);
            for (int j=0; j<words[i].size(); j++){
                if (i==0 or ascii1[words[i][j]-'a']>0){
                    ascii2[words[i][j]-'a']+=1;
                    if (i!=0) ascii1[words[i][j]-'a']-=1;
                    // if (i!=0 and mpp1[words[i]]==0) mpp1.erase(words[i]);
                }
            }
            ascii1=ascii2;
        }
        for (int i=0; i<26; i++){
            char ch='a'+i;
            string cur;
            cur=ch;
            for (int j=0; j<ascii1[i]; j++){
                ans.push_back(cur);
            }
        }
        return ans;
    }
};