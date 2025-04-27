class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return {{}};
        vector<vector<int>> ans={{1}};
        // vector<int> tworow={1,1};
        if (numRows==1) return ans;
        // if (numRows==2) return tworow;
        for (int i=2; i<=numRows; i++){
            vector<int> cur;
            // if (i==1) cur=onerow;
            // if(i==2) cur= tworow;
            cur.push_back(1);
            if (i>2){
                for (int j=0; j<ans[i-2].size()-1; j++){
                    int num= ans[i-2][j]+ans[i-2][j+1];
                    cur.push_back(num);
                }
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};