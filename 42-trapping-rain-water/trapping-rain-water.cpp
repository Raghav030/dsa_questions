class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> l(height.size(),0);
        vector <int> r(height.size(),0);
        int temp1= height[0];
        int temp2=height[height.size()-1];
        for (int i=0; i<height.size(); i++){
            if (height[i]>temp1){
                l[i]=height[i];
                temp1=height[i];
            }
            else l[i]= temp1;
            if (height[height.size()-i-1]> temp2){
                temp2=height[height.size()-i-1];
            }
            r[height.size()-i-1]=temp2;
        }
        int ans=0;
        for (int i=0; i<height.size(); i++){
            // if (min(l[i],r[i])-height[i] >0)
            ans+=max((min(l[i],r[i])-height[i]),0);
        }
        return ans;
    }
};