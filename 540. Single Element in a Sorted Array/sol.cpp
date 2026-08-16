class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int mid = (l + r) >> 1;
            if((mid % 2 == 0 and nums[mid] == nums[mid + 1]) or (mid % 2 and nums[mid] == nums[mid - 1]))
                l = mid + 1;

            else
                r = mid;
        }
        
        return nums[l];
    }
};
