class Solution {
public:
    bool rotateString(string s, string goal) {
        int n= s.size();
        if (goal.size() != n) return false;
        for (int i=0; i<n; i++){
            int j=0, ind=i;
            while (s[ind]==goal[j]){
                ind= (ind+1)%n;
                j+=1;
            }
            if (j==n) return true;
        }
        return false;
    }
};