//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int maxcapacity(int W, int n, int wt[], int val[],vector<vector<int>>& valperweight){
        if (W<=0 or n<0){
            return 0;
        }
        if (valperweight[n][W] != -1){
            return valperweight[n][W];
        }
        if (wt[n]<=W){
            int take= val[n] + maxcapacity(W-wt[n], n-1, wt, val, valperweight);
            int nottake= maxcapacity(W, n-1, wt, val, valperweight);
            return valperweight[n][W]= max(take, nottake);
            }
        else {
            return valperweight[n][W]= maxcapacity(W, n-1, wt, val, valperweight);
        }    
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> valperweight(n, vector<int> (W+1, -1));
       return maxcapacity(W, n-1, wt, val, valperweight);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends