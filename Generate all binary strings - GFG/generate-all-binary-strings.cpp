//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void printstrings(int num, string binary){
        if (num==binary.size()){
            cout<<binary<<" ";
            return;
        }
        if (binary[binary.size()-1]=='0'){
            printstrings(num, binary+'0');
            printstrings(num, binary+'1');
        }
        else {
            printstrings(num, binary+'0');
        }
    }
    void generateBinaryStrings(int num){
        //Write your code
        string binary;
        binary.push_back('0');
        printstrings(num, binary);
        binary[0]='1';
        printstrings(num, binary);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends