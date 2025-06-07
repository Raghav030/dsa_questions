class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        int right = m*n-1;
        int left=0;
        while (left<=right){
            int lmid=((left+right)/2)/n;
            int rmid= ((left+right)/2)%n;
            if (matrix[lmid][rmid]== target) return true;
            else if (matrix[lmid][rmid]<target){
                left=lmid*n+ rmid+1;
            }
            else if (matrix[lmid][rmid]> target){
                right =lmid*n+ rmid-1;
            }

        }
        return false;

    }
};