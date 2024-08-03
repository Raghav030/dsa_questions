class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp;
        int n= arr.size();
        for (int i=0; i<n;i++){
           mpp[arr[i]]+=1; 
        }
        for (int i=0; i<n; i++){
            if (mpp.find(target[i])== mpp.end()) return false;
            mpp[target[i]]-=1;
            if (mpp[target[i]]==0) mpp.erase(target[i]);
        }
        return true;
    }
};