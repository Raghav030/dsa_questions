//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    void fsetbits(int num, vector<int>& vect){
        int i=0;
        while (num != 0){
            int temp =num & 1;
            vect[i]= vect[i]+ temp;
            num>>=1;
            i+=1;
        }
    }
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector <int> vect(31, 0);
    	for (int i=0; i<n; i++){
    	    fsetbits(arr[i], vect);
    	}
    	long long ans=0;
    // 	int i=0;
        long long j=1;
    	for (int i=0; i<=31; i++){
    	    ans= ans+ 1LL*(1LL*vect[i]*(1LL*(n-vect[i]))* (1LL*j));
    	    j*=2;
    	}
    // 	int temp =2 &1;
    // 	cout << temp;
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends