class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size(), row, col, new_row, new_col, cur, next_num;
        for (int i=0; i<(n+1)/2;i++){
            for(int j=0; j<(n)/2; j++){
                row=i, col=j;
                cur=matrix[row][col];
                new_row= col, new_col=n-1-row;
                next_num= matrix[new_row][new_col];
                matrix[new_row][new_col]=cur;
                row=new_row, col= new_col;
                cur= next_num;
                // row=new_row, col=new_col;
                new_row= col, new_col= n-1-row;
                next_num= matrix[new_row][new_col];
                matrix[new_row][new_col]=cur;
                cur= next_num;
                row=new_row, col=new_col;
                new_row= col,new_col=n-1-row;
                next_num= matrix[new_row][new_col];
                matrix[new_row][new_col]=cur;
                cur= next_num;
                row=new_row, col=new_col;
                new_row= col, new_col=n-row-1;
                next_num= matrix[new_row][new_col];
                matrix[new_row][new_col]=cur;

            }
        }
        
    }
};