class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // max(maxsumsubarray, totalsum - minsumsubarray)
        int ts = 0, maxs = 0, mins = 0, minans = INT_MAX, ans = INT_MIN;

        for(int x : nums) {
            ts += x, maxs += x, mins += x;
            maxs = max(maxs, x);
            mins = min(mins, x);
            ans = max(ans, maxs);
            minans = min(minans, mins);
        }

        return ts == minans ? ans : max(ans, ts - minans);
    }
};
