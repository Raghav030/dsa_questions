class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.size();
        int i=0;
        if (n<=k) return "0";
        while (i<num.size()-1 and k>0){
            if (num[i] != '0' and num[i]>num[i+1]){
                num.erase(i, 1);
                if (i>0) i-=1;
                k-=1;
            }
            else i+=1;
        }
        while (num.size()>=2 and k>0 and num[num.size()-1]>=num[num.size()-2]){
            num.erase(num.size()-1, 1);
            k-=1;
        }
        for (i=0; i<num.size(); i++){
            if (num[i] != '0') break;
            num.erase(i, 1);
            i-=1;
        }
        if (num.size()==0) return "0";
        return num;
    }
};