class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, prod = 1, j = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            
            while(prod >= k and j <= i) {
                prod /= nums[j];
                j += 1;
            }
            
            ans += i - j + 1;
        }
        
        return ans;
    }
};
