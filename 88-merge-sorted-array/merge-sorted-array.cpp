class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_ind=m-1, nums2_ind= n-1;
        for (int i=n+m-1; i>=0; i--){
            if (nums1_ind>=0 and nums2_ind>=0 and nums1[nums1_ind]>nums2[nums2_ind]) {
                nums1[i]= nums1[nums1_ind];
                nums1_ind-=1;
            }
            else if (nums1_ind>=0 and nums2_ind>=0 ) {
                nums1[i]=nums2[nums2_ind];
                nums2_ind-=1;
            }
            else if (nums2_ind>=0) {
                nums1[i]=nums2[nums2_ind];
                nums2_ind--;
            }
            else if (nums1_ind>=0) {
                nums1[i]=nums1[nums1_ind];
                nums1_ind--;
            }
        }
    }
};