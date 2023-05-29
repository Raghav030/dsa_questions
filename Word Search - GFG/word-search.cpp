//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fword(vector<vector<char>> board, string word, int row, int col, int ind, vector <vector<int>>& vis){
        if (ind==word.size()) return true;
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        vector <int> rvect= {0,-1,0,1};
        vector <int> cvect= {1, 0, -1,0};
        for (int i=0; i<4; i++){
            int rnext=row+rvect[i];
            int cnext= col+cvect[i];
            if (rnext>=0 and cnext>=0 and rnext<n and cnext<m and word[ind]==board[rnext][cnext] and vis[rnext][cnext]==0){
                if (fword(board, word, rnext, cnext, ind+1, vis)==true) return true;
                vis[rnext][cnext]=0;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        vector <vector<int>> vis(n, vector <int>(m,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] ==word[0]){
                    if (fword(board, word, i, j, 1, vis) == true) return true;
                }    
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends