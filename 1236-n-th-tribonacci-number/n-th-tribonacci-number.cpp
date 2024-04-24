class Solution {
public:
    int ftribonacci(int n, vector<int>& vect){
        if (vect[n]!= -1) return vect[n];
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 1;
        return vect[n]= ftribonacci(n-1, vect)+ ftribonacci(n-2, vect)+ ftribonacci(n-3, vect);
    }
    int tribonacci(int n) {
        vector<int> vect(n+1, -1);
        vect[0]=0;
        if (n>=1)vect[1]=1;
        if (n>=2) vect[2]=1;
        return ftribonacci(n, vect);
    }
};