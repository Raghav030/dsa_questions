class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n= students.size();
        int j=0, flag=0;
        while (j<n){
            flag=0;
            for (int i=0; i<n; i++){
                if (j<n and sandwiches[j]== students[i]){
                    j+=1;
                    students[i]=-1;
                    flag=1;
                }
            }
            if (flag==0) break;
        }
        return n-j;
    }
};