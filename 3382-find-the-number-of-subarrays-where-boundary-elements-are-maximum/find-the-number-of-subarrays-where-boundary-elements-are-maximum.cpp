class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        
//         for (int i=0; i<n; i++){
//             if (flag==-1){
//                 i=next;
//                 flag=0;
//             }
//             int first=nums[i] , maxi= nums[i];
//             int cur=0;
//             for (int j=i; j<n; j++){
//                 if (nums[j]<st.top()){
//                     st.push(nums[j]);
//                 }
//                 if (nums[j]==nums[i]) {
//                     flag=-1;
//                     next=j;
//                     cur+=1;
//                     // ans+=1;
//                 }
//                 if (nums[j]>nums[i]) {
//                     // flag=-1;
//                     // next=j;
//                     break;
//                 }
                
//             }
            
//             ans=ans+ cur*(cur+1)/2;
//         }
        int n=nums.size();
        long long ans=0;
        // int flag=0, next=0;
        stack<int> st;
        stack<int>st2;
        st.push(nums[0]);
        long long cur=1;
        for (int i=1; i<n; i++){
            if (nums[i]< st.top()){
                st2.push(cur);
                cur=1;
                st.push(nums[i]);
            }
            else if (nums[i]== st.top()){
                cur+=1;
            }
            else {
                
                st2.push(cur);
                while(!st.empty() and nums[i]>st.top()){
                
                    cur= st2.top();
                    ans=ans+cur*(cur+1)/2;
                    cout<<st.top()<<' '<<st2.top()<<endl;
                    st.pop();
                    st2.pop();
                    
                }
                cout<<st.size()<<endl;
                cur= (st2.empty() or st.top()>=nums[i])? 1: st2.top();
                if (!st.empty() and st.top()==nums[i]) {
                    cur=st2.top()+1;
                    st2.pop();
                }
                if (st.empty() or st.top() != nums[i]) st.push(nums[i]);
                // cout<<cur;
            }
            
        }
        st2.push(cur);
        while (!st.empty()){
            cur=st2.top();
            cout<<st.top()<<' '<<st2.top()<<endl;

            ans= ans+ cur*(cur+1)/2;
            st.pop();
            st2.pop();
        }
        return ans;
    }
};