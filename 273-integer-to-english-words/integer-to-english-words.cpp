class Solution {
public:
    void frepresentation(int i, string&  ans){
        if (i==1) ans=ans+"One ";
        if (i==2) ans=ans+"Two ";
        if (i==3) ans=ans+"Three ";
        if (i==4) ans=ans+"Four ";
        if (i==5) ans=ans+"Five ";
        if (i==6) ans=ans+"Six ";
        if (i==7) ans=ans+"Seven ";
        if (i==8) ans=ans+"Eight ";
        if (i==9) ans=ans+"Nine ";

    }
    void fthreenum(int num, string& ans){
        unordered_map<int, string> mpp_tees={
            {20, "Twenty "},
            {30,"Thirty "},
            {40,"Forty "},
            {50,"Fifty "},
            {60, "Sixty "},
            {70, "Seventy "},
            {80, "Eighty "},
            {90, "Ninety "}};
        unordered_map<int, string> map_teens={
            {10, "Ten "},
            {11,"Eleven "},
            {12, "Twelve "},
            {13,"Thirteen "},
            {14, "Fourteen "},
            {15, "Fifteen "},
            {16, "Sixteen "},
            {17, "Seventeen "},
            {18, "Eighteen "},
            {19, "Nineteen "}
        };
        if (num/100 != 0){
            frepresentation(num/100, ans);
            ans=ans+"Hundred ";
        }
        if ((num%100) != 0){
            // frepresentation(num/10, ans);
            int temp= (num%100)/10 * 10;
            if ((num%100)/10 ==1) ans=ans+ map_teens[(num%100)];
            else {
                if ((num%100)/10 != 0) ans= ans+ mpp_tees[temp];
                frepresentation(num%10, ans);
            }
        }
        // else{

        // }
    }
    string numberToWords(int num) {
        if (num==0) return "Zero";
        string ans= "";
        if (num/ 1000000000 != 0){
            fthreenum(num/ 1000000000, ans);
            ans= ans+"Billion ";
        }
        if ((num%1000000000)/1000000 != 0){
            int temp= (num%1000000000)/1000000;
            fthreenum(temp, ans);
            ans=ans+"Million ";
        }
        if ((num%1000000)/1000 != 0){
            int temp= (num%1000000)/1000;
            fthreenum(temp, ans);
            ans= ans+"Thousand ";
        }
        if ((num%1000) !=0){
            int temp= (num%1000);
            fthreenum(temp, ans);
        }
        ans.pop_back();
        return ans;
    }
};