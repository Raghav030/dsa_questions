//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n= matrix.size();
        int m= matrix[0].size();
        vector <int> rvect={-1, 0, 1, 0,1,-1, 1, -1};
        vector <int> cvect={0, -1, 0, 1, -1, 1, 1, -1};
        int ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int num=0;
                for (int k=0; k<8; k++){
                    int rnext= i+rvect[k];
                    int cnext= j+cvect[k];
                    if (matrix[i][j]==1 and rnext>=0 and cnext>=0 and rnext<n and cnext<m and matrix[rnext][cnext]==0) num+=1;
                }
                if (num>0 and num%2==0) ans+=1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends