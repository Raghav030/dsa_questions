class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size(), ans=0, cur, width, length;
        stack<int> st;
        vector<int> rArea(n);
        vector<int> lArea(n);
        for (int i=0; i<n; i++){
            // width=0;
            while (!st.empty() and heights[i]<heights[st.top()]){
                // width+=1;
                // width= abs(i- st.top()+1);
                // length= heights[st.top()];
                // cur= length* width;
                rArea[st.top()]= i;
                // ans= max(cur, ans);
                st.pop();
            }
            // if (st.empty()) width=0;
            st.push(i);
        }
        // width=0;
        while (!st.empty()){
            // length= heights[st.top()];
            // width+=1;
            // width= abs(n-1- st.top()+1);
            // cur= length* width;
            rArea[st.top()]= n;
            // ans= max(ans, cur);
            st.pop();
        }
        width=0;
        for (int i=n-1; i>=0; i--){
            // width=0;
            while (!st.empty() and heights[st.top()]>heights[i]){
                // width= abs(i- st.top());
                // length= heights[st.top()];
                // cur =width*length- length*1;
                // cout<< i<< ' '<< width*length- length*1<<endl;
                lArea[st.top()]=i;
                st.pop();
            }
            // if (st.empty()) width=0;
            st.push(i);
        }
        // width=0;
        while (!st.empty()){
            // width+=1;
            // width= abs( st.top());
            // length= heights[st.top()];
            // cur= width* length- length*1;
            lArea[st.top()]= -1;
            st.pop();
        }
        cur=0;
        for (int i=0; i<n; i++){
            cur = (rArea[i]- lArea[i]-1)* heights[i];
            // cout<<i<< ' '<< rArea[i]<< ' '<<' '<<lArea[i]<<endl;
            ans= max(ans, cur);
        }
        return ans;
    }
};