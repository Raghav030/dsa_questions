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
        for(int i=0; i<n+k-1; i++){
            if (i!=0 and colors[i%n] == colors[(i-1)%n]){
                j=i;
            }
            if (i-j+1>=k) {
                cout<<i<<i-j+1<<endl;
                ans+=1;
            }
            // i+=1;
            // else{
            //     i=i+1;
            //     j=i;
            // }
            
        }
        return ans;
    }
};