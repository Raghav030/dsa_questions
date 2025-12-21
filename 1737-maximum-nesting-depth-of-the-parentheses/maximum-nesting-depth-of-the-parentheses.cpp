class Solution {
public:
    int maxDepth(string s) {
        int n= s.size(), max_depth=0, cur_depth=0;
        for (int i=0; i<n; i++){
            if (s[i]=='(') cur_depth+=1;
            else if (s[i]==')') cur_depth-=1;
            max_depth=max(max_depth, cur_depth);
        }
        return max_depth;
    }
};