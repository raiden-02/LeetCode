class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        
        auto getMin = [](int part, vector<int> &nums) {
            return part == (int)nums.size() ? INT_MAX : nums[part];
        };
        
        auto getMax = [](int part, vector<int> &nums) {
            return part == 0 ? INT_MIN : nums[part - 1];
        };
        
        int l = 0, r = m, len = m + n;
        
        while(l <= r) {
            int part1 = (l + r) >> 1;
            int part2 = ((len + 1) / 2) - part1; //part1 + part2 = len / 2;
            
            int left1 = getMax(part1, nums1);
            int right1 = getMin(part1, nums1);
            
            int left2 = getMax(part2, nums2);
            int right2 = getMin(part2, nums2);
            
            if(left1 <= right2 and left2 <= right1) {
                if(len % 2 == 0)
                    return (double)(max(left1, left2) + min(right1, right2)) / 2;
                return max(left1, left2);
            }
            
            if(left1 > right2)
                r = part1 - 1;
            else
                l = part1 + 1;
        }
        
        return -1;
    }
};

// --- alternate solution ---

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> mergedArr(nums1.size() + nums2.size());
        
        int i = 0, j = 0, n = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j])
                mergedArr[n++] = nums1[i++];
            
            else if(nums2[j] <= nums1[i])
                mergedArr[n++] = nums2[j++];
            
        }
        
        while(i < nums1.size())
            mergedArr[n++] = nums1[i++];
        
        while(j < nums2.size())
            mergedArr[n++] = nums2[j++];
        
        for(double &i : mergedArr)
            cout << i << " ";
        
        n = mergedArr.size();
        int mid = n / 2;
        
        return n % 2 == 0 ? (mergedArr[mid] + mergedArr[mid - 1]) / 2 : mergedArr[mid];
    }
};
