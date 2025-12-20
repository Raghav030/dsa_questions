class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size(), largest_common_prefix=0, flag=1;
        string ans="";
        if (n==0) return "";
        while (flag==1){
            if (largest_common_prefix>=strs[0].size()) break;
            // if ()
            int cur = strs[0][largest_common_prefix];
            for (int i=0; i<n; i++){
                if (largest_common_prefix>=strs[i].size() or strs[i][largest_common_prefix]!=cur){
                    flag=0;
                    break;
                }
            }
            if (flag==1) {
                largest_common_prefix+=1;
                ans+=cur;
            }
        }
        return ans;
    }
};