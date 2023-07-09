//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int ans=0;
        for (int i=0; i<=29; i++){
            if (!(1<<i & N)) {
                int j=i;
                while (j<=29){
                    if (1<<j & N) break;
                    j+=1;
                }
                if (j==30) return N;
                N+=(pow(2,i));
                break;
            }
        }
        return N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends