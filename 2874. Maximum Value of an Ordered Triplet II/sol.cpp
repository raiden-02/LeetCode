class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        size_t n = nums.size();
        vector<long long> prefixMax(n);
        prefixMax[n - 1] = nums[n - 1];
        
        for(int i = n - 2; i >= 0;  i--) {
            prefixMax[i] = max(prefixMax[i + 1], (long long)nums[i]);
        }
                
        long long maxm = nums[0];
        long long ans = numeric_limits<long long>::min();
                
        for(size_t i = 1; i < n - 1; i++) {
            long long curd = maxm - nums[i];
            ans = max(ans, (long long)curd * prefixMax[i + 1]);     
            maxm = max(maxm, (long long)nums[i]);
        }
        
        return ans < 0 ? 0 : ans;
    }
};
