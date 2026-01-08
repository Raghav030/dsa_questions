class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums2, vector<int>& nums1) {
        int n= nums1.size(), m= nums2.size();
        vector<int> vect(n), ans;
        stack<int> st;
        for (int i=0; i<n; i++){
            if (st.size()==0 or nums1[st.top()]> nums1[i]){
                st.push(i);
            }
            else{
                while (st.size() >0 and nums1[st.top()]<=nums1[i]){
                    // pair<int, int> cur_element= st.top();
                    cout<<i<<' ';
                    vect[st.top()]= nums1[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (st.size()>0){
            vect[st.top()]= -1;
            st.pop();
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (nums2[i]== nums1[j]){
                    ans.push_back(vect[j]);
                    break;
                }
            }
        }
        return ans;
    }
};