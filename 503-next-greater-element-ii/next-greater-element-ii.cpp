class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size(), j=0, i=0;
        stack<int> st;
        vector<int> ans(n,-1);
        if (nums.size()==0) return {};
        while (true){
            i= j%n;
            // cout<<i;
            if (st.size()>0 and st.top()==i){
                while(st.size()>0){
                    ans[st.top()]=-1;
                    st.pop();
                }
                break;
            }
            while (st.size()>0 and nums[st.top()]<nums[i]){
                ans[st.top()]= nums[i];
                st.pop();
            }
            if(j<n) st.push(i);
            j+=1;
            // if (st.size()==0 or nums[st.top()] <nums[i])
        }
        return ans;
    }
};