class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.size(), i=n-1, flag=0;
        string ans="";
        while (i>=0){
            if ((num[i]-'0')%2 != 0){
                flag=1;
                break;
            }
            // if (flag==1) break;
            i-=1;
        }
        for (int j=0; j<=i; j++){
            // if (ans.size()==0 and num[j]=='0') continue;
            ans+=num[j];
        } 
        return ans;
    }
};