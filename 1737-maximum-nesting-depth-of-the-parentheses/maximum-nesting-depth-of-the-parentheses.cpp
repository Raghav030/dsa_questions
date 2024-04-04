class Solution {
public:
    int maxDepth(string s) {
        int maxi_depth=0;
        int n=s.size();
        int cur_depth=0;
        for (int i=0; i<n; i++){
            if (s[i]=='(') cur_depth+=1;
            if (s[i]==')') cur_depth-=1;
            maxi_depth=max(maxi_depth, cur_depth);
            if (cur_depth<0) return -1;
        }
        if (cur_depth != 0) return -1;
        return maxi_depth;

    }
};