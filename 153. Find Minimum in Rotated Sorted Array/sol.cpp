class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int mid = (l + r) >> 1;
            
            if(nums[mid] > nums[l] and nums[mid] > nums[r])
                l = mid + 1;
            
            else if(nums[mid] < nums[l] and nums[mid] < nums[r])
                r = mid;
            
            else break;
        }

        return min(nums[l], nums[r]);
    }
};
