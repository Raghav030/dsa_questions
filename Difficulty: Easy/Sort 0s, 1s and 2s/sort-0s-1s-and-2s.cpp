//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        vector<int> temp(3,0);
        int k=0, n=arr.size();
        for (int i=0; i<3; i++){
            int cur=0;
            for (int j=0; j<n; j++){
                if (arr[j]==i)  cur+=1;
            }
            temp[i]=cur;
        }
        for (int i=0; i<n; i++){
            while (temp[k]==0){
                k+=1;
                if (k>=3) break;
            }
            arr[i]=k;
            temp[k]-=1;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends