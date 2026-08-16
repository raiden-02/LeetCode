class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1; m--; n--;
        while(pos >= 0) {
            if(m < 0)
                nums1[pos] = nums2[n--];
            else if(n < 0)
                nums1[pos] = nums1[m--];
            else {
                if(nums1[m] > nums2[n])
                    nums1[pos] = nums1[m--];
                else
                    nums1[pos] = nums2[n--];
            }
            pos--;
        }
    }
};
