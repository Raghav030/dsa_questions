//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n= arr.size(), num_even=0;
        // vector<int> arr1(n);
        queue<int> pos_q, neg_q;
        for (int i=0; i<n; i++) {
            // arr1[i]=arr[i];
            arr[i]>=0 ? pos_q.push(arr[i]): neg_q.push(arr[i]);
            // if (arr[i] >0) num_even+=1;
        }
        int i=0;
        while (!pos_q.empty() and !neg_q.empty()){
            if (i%2==0) {
                arr[i]=pos_q.front();
                pos_q.pop();
            }
            else {
                arr[i]= neg_q.front();
                neg_q.pop();
            }
            i+=1;
        //     if (arr1[i]>=0) {
        //         arr[j]=arr1[i];
        //         j= (j+2)>n ?  j+=1: j+=2 ;
        //     }
        // }
        // j=1;
        // for (int i=0; i<n; i++){
        //     if (arr1[i]<0){
        //         arr[j]=arr1[i];
        //         j= (j+2)>n ?  j+=1: j+=2 ;
        //     }
        }
        while (!pos_q.empty()){
            arr[i]=pos_q.front();
            i+=1;
            pos_q.pop();
        }
        while (!neg_q.empty()){
            arr[i]=neg_q.front();
            i+=1;
            neg_q.pop();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends