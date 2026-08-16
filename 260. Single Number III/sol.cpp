class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long mask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        mask &= -mask;
        vector<int> ans = {0, 0};
        
        for(int x : nums) {
            if(x & mask) ans[0] ^= x;
            else ans[1] ^= x;
        }
        
        return ans;
    }
};
