class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long pairsum = 0, ans = 0;
        int l = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            pairsum += mp[nums[i]];
            mp[nums[i]]++;

            while(l <= i and pairsum >= k) {
                ans += (n - i); //add the no of arrays which are longer than this to the answer as well
                pairsum -= mp[nums[l]] - 1; //new no of pairs after decrementing freq of leftmost char of sliding window
                mp[nums[l++]]--;
            }    
        }

        return ans;
    }
};
