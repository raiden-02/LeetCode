class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        int maxFreq = 0;

        for(auto &x : mp) maxFreq = max(maxFreq, x.second);

        if(maxFreq <= n / 2) {
            return n % 2;
        }

        return 2 * maxFreq - n;
    }
};
