class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        stack<int> st;
        vector<int> ans;
        for (int i=0; i<n; i++){
            // if (asteroids[i]>=0) st.p
            if (asteroids[i]<0 and st.size()>0 and st.top()>0){
                while (st.size()>0 and st.top()< abs(asteroids[i]) and st.top()>0) st.pop();
                if (st.size()>0 and st.top()== abs(asteroids[i]) and st.top()>0){
                    st.pop();
                    continue;
                }
                if (st.size()>0 and st.top()> abs(asteroids[i]) and st.top()>0) continue;
            }
            st.push(asteroids[i]);
        }
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        for (int i=0; i<ans.size()/2; i++){
            swap(ans[i], ans[ans.size()-i-1]);
        }
        return ans;
    }
};