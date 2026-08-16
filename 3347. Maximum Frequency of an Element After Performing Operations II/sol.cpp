class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        size_t n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        unordered_set<int> values;

        for(int x : nums) {
            freq[x]++;
            values.insert(x);
            if(x - k >= nums.front()) values.insert(x - k);
            if(x + k <= nums.back()) values.insert(x + k);
        }

        for(int x : values) {
            int l = lower_bound(nums.begin(), nums.end(), x - k) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), x + k) - nums.begin();

            int best_freq = min(r - l, freq[x] + numOperations);
            ans = max(ans, best_freq);
        }

        return ans;
    }
};
