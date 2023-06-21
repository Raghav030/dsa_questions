//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set <int> st;
      for (int i=0; i<N; i++) st.insert(arr[i]);
      int ans=0;
      while (!st.empty()){
          int cur_len=0;
          auto it=st.begin();
          int num =*it;
          int temp=num;
          while (st.find(temp)!= st.end()){
              cur_len+=1;
              st.erase(temp);
              temp-=1;
          }
          num+=1;
          while (st.find(num) != st.end()){
              cur_len+=1;
              st.erase(num);
              num+=1;
          }
          ans=max(cur_len, ans);
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends