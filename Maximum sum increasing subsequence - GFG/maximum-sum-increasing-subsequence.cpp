//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
// 	void fmaxi(int arr[], )
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // int i=0, j=0;
	    int ans=0;
	   // priority_queue<pair<int, int>> pq;
	   // int temp=0;
	   // while (i<n){
	   //     temp+=arr[i];
	   //     pq.push({arr[i], i});
	   //     while (pq.top().first> arr[i]){
	   //         temp-=pq.top().first;
	   //         int cur= pq.top().second+1;
    // 	        j= max(j, cur);
    // 	        pq.pop();
	   //     }
	   //    // int temp= i-j+1;
	   //     ans= max(ans, temp);
	   //     i+=1;
	   // }
	   // return ans;
	   vector <int> maxi(n, 0);
	   for (int i=0; i<n; i++){
	       //int cur= arr[i];
	       int temp=0;
	       for (int j=0; j<=i; j++){
               int cur= arr[i];
	           if (arr[i]> arr[j]) {
	               cur= maxi[j]+arr[i];
	           }
	           //else int cur= maxi[j];
	           temp= max(temp, cur);
	       }
	       maxi[i]=temp;
	   }
	   for (int i=0; i<n; i++) ans= max(ans, maxi[i]);
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
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends