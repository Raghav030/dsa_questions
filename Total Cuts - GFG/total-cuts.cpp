//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector <int> leftmax(N,A[0]);
        vector <int> rightmin(N,A[N-1]);
        for (int i=1; i<A.size(); i++){
            leftmax[i]=max(leftmax[i-1], A[i]);
            rightmin[N-i-1]=min(rightmin[N-i], A[N-i-1]);
        }
        int ans=0;
        for (int i=0; i<A.size()-1; i++){
            if (leftmax[i]+rightmin[i+1]>= K) ans+=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends