class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        size_t n = nums.size();
        
        for(size_t x = 0; x < n; x++) {
            bool f = true;
            
            if(x + k >= n || x + 2 * k > n) return false;

            for(size_t y = x + 1; y < x + k && y < n; y++) {
                if(nums[y] <= nums[y - 1]) {
                    f = false;
                    break;
                }
            }

            for(size_t z = x + k + 1; f && z < x + 2 * k && z < n; z++) {
                if(nums[z] <= nums[z - 1]) {
                    f = false;
                    break;
                }
            }

            if(f) return true;
        }

        return false;
    } 
};
