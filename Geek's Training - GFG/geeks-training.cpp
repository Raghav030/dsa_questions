//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> total_points(n, vector<int>(3, 0));
        for (int i=0; i<3; i++){
            total_points[0][0]=points[0][0];
            total_points[0][1]=points[0][1];
            total_points[0][2]=points[0][2];
        }
        for (int i=1; i<n; i++){
            for (int task=0; task<3; task++){
                
                for (int last=0; last<3; last++){
                    if (task !=last){
                        total_points[i][task]=max(total_points[i][task], total_points[i-1][last]+points[i][task]);
                    }    
                }
            }
        }
        int ans=0;
        for (int i=0; i<3; i++){
            ans=max(ans, total_points[n-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends