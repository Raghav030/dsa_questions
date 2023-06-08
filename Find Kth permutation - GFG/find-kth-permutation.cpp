//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int factorial(int n){
        if (n==0 or n==1) return 1;
        return n*factorial(n-1);
    }
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> vect(n,0);
        for (int i=0; i<n; i++) vect[i]=i+1;
        string ans="";
        int temp=0;
        for (int i=n-1; i>=0; i--){
            int numbers_crossed = factorial(i);
            for (int j=0; j<n; j++){
                if (vect[j] !=0 and temp<k){
                    temp+=numbers_crossed;
                }
                if(temp>=k and vect[j] !=0){
                    ans+=to_string(vect[j]);
                    vect[j]=0;
                    temp=temp-numbers_crossed;
                    break;
                    // k=k-(temp-numbers_crossed);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends