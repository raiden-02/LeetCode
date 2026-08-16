class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();

        while(i < m && j < n) {
            int a = INT_MAX, b = INT_MAX;
            
            if(i < m) a = nums1[i];
            if(j < n) b = nums2[j];

            if(a < b) i++;
            else if(b < a) j++;
            else if(a == b && a != INT_MAX) return a;
            else break;
        }

        return -1;
    }
};
