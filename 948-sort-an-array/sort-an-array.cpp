class Solution {
public:
    void mergesort(vector<int>& nums, int l, int r, int mid){
        vector<int> temp(r-l+1);
        int i=l, j=mid+1, k=0;
        while (i<=mid and j<=r){
            if (nums[i]< nums[j]){
                temp[k]=nums[i];
                i+=1;
                k+=1;
            }
            else {
                temp[k]=nums[j];
                j+=1;
                k+=1;
            }
        }
        while (i<=mid){
            temp[k]=nums[i];
            i+=1;
            k+=1;
        }
        while (j<=r){
            temp[k]=nums[j];
            j+=1;
            k+=1;
        }
        i=l, j=0;
        for (i=l; i<=r; i++){
            nums[i]=temp[j];
            j+=1;
        }
    }
    void merge(vector<int>& nums, int l, int r){
        int mid=(l+r)/2;
        if (r>l){
            merge(nums, l, mid);
            merge(nums, mid+1, r);
        }
        mergesort(nums, l, r, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size();
        merge(nums, 0, n-1);
        return nums;
    }
};