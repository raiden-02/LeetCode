class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        size_t n = nums.size();

        if(n <= 1) return true;

        int comp = nums[1] > nums[0] ? 0 : nums[1] < nums[0] ? 1 : 2; 

        for(size_t i = 2; i < n; i++) {
            if(comp == 2) {
                comp = nums[i] > nums[i - 1] ? 0 : nums[i] < nums[i - 1] ? 1 : 2; 
                continue;
            }

            if(nums[i] > nums[i - 1] && comp == 0) {
                continue;
            }

            else if(nums[i] < nums[i - 1] && comp == 1) {
                continue;
            }

            else if(nums[i] == nums[i - 1] && (comp == 0 || comp == 1)) {
                continue;
            }

            else return false;
        }

        return true;
    }
};
