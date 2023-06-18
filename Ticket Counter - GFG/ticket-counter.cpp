//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        vector <int> arr(N,0);
        int prev=0;
        for (int i=0; i<N; i+=K){
            // if(arr[i]==0) return N-i; 
            for (int j=0; j<K; j++){
                if (arr[i+j]==1){
                    return prev+1;
                }
                prev=i+j;
                arr[i+j]=1;
                
            }
            for (int j=0; j<K; j++){
                if (arr[N-i-j-1]==1){
                    return prev+1;
                }
                arr[N-i-j-1]=1;
                prev=N-i-j-1;
            }
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends