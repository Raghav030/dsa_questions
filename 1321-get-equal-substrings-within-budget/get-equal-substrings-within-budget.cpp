class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int ans=0, j=-1, curcost=0;
        for (int i=0; i<n; i++){
            curcost=curcost+ (abs(s[i]-t[i]));
            while (curcost>maxCost and j<=i){
                curcost=curcost- (abs(s[j+1]-t[j+1]));
                j+=1;
            }
            if (ans<(i-j)) ans=i-j;
        }
        return ans;
    }
};