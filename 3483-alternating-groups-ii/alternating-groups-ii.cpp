class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n= colors.size(), i=0, j=0, ans=0;
        // if (n%2==0){
        //     if (k<n) return n;
        //     if (k==n) return 1;
        //     return 0;
        // }
        // else{
        //     if (k>=n) return 0;
        //     return n-k+1;
        // }
        // return 0;
        for(int m=0; m<n+k-1; m++){
            if (i-j+1>=k) {
                cout<<i<<i-j+1<<endl;
                ans+=1;
            }
            i+=1;
            if (colors[i%n] == colors[(i-1)%n]){
                j=i;
            }
            // else{
            //     i=i+1;
            //     j=i;
            // }
            
        }
        return ans;
    }
};