class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> dis[n];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                dis[i].push_back(1e9);
            }
        }
        for (int i=0; i<edges.size(); i++){
            dis[edges[i][0]][edges[i][1]]=(edges[i][2]);
            dis[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        int ans=n;
        int city=0;
        for (int i=0; i<n; i++){
            int temp=0;
            for (int j=0; j<n; j++){
                if (i !=j and dis[i][j]<=distanceThreshold){
                    temp+=1;
                }
            }
            if (temp<=ans){
                city=i;
                ans=temp;
            }
        }
        return city;
    }
};