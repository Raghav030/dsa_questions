class Solution {
public:
    vector<long long> previous_smallest_element(vector<int>& arr){
        // int  n= arr.size(), cur_min= arr[0];
        // vector<int> pse(n);
        // stack<int> st;

        // for (int i=0; i<n; i++){
        //     // int cur= arr[i];
        //     // cur_min= min(cur_min, cur);
        //     // pse[i]= cur_min;
        //     while (st.size()>0 and arr[st.top()] >arr[i]){
        //         arr[st.top()]= i;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        // while (!st.empty()){
            
        // }
        // return pse;
        int n= arr.size();
        vector<long long> smallest_upto_ahead(n);
        stack<int> st;
        for (int i=0; i<n; i++){
            while (st.size()>0 and arr[st.top()]>arr[i]){
                smallest_upto_ahead[st.top()]= 1LL*(i-1);
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()){
            smallest_upto_ahead[st.top()]=1LL* (n-1);
            st.pop();
        }
        return smallest_upto_ahead;
    }
    vector<long long> next_smallest_element(vector<int>& arr){
        // int n= arr.size(), cur_min= arr[n-1];
        // vector<int> nse(n);
        // for (int i=n-1; i>=0; i--){
        //     int cur= arr[i];
        //     cur_min= min(cur_min, cur);
        //     nse[i]=cur_min;
        // }
        // return nse;
        int n= arr.size();
        vector<long long> smallest_upto_before(n);
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() and arr[st.top()]>=arr[i]){
                smallest_upto_before[st.top()]= 1LL* (i+1);
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()){
            smallest_upto_before[st.top()]=1LL* 0;
            st.pop();
        }
        return smallest_upto_before;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod= 1e9+7;
        // int n= arr.size(), ans=0, left_num, right_num;
        // if (n==0) return 0;
        // int mod=1e9+7;
        // vector<int> nse , pse;
        // pse= previous_smallest_element(arr);
        // nse= next_smallest_element(arr);
        // for (int i=0; i<n; i++){
        //     left_num=0;
        //     right_num=0;
        //     for (int j=i+1; j<n; j++){
        //         if (pse[j]!= arr[i]) break;
        //         // if (arr[j])
        //         right_num+=1; 
        //     }
        //     for (int j=i-1; j>=0; j--){
        //         if (nse[j] != arr[i]) break;
        //         if (arr[j]== arr[i]) break;
        //         left_num+=1;
        //     }
        //     cout<<left_num<<' '<<right_num<<endl;
        //     ans= (ans + (1LL* (left_num+1)* (right_num+1)) %mod)%mod;
        // }
        // return ans;
        int n= arr.size();
        vector<long long> smallest_upto_ahead= next_smallest_element(arr);
        vector<long long> smallest_upto_before= previous_smallest_element(arr);
        long long ans=0;
        for (int i=0; i<n; i++){
            // cout<< smallest_upto_before[i]<<' '<<smallest_upto_ahead[i]<<endl;
            ans= ans%mod + (1LL* arr[i]*(1LL* (1LL* abs(smallest_upto_before[i]-i)+1)) *(1LL*(1LL* abs(smallest_upto_ahead[i]-i)+1)))%mod;
        }
        return ans;
    }
};