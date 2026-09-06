class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxval(n), minval(n);
        maxval[0] = nums[0];
        minval[n - 1] = nums[n - 1];

        for (int l = 1, r = n - 2; l < n && r >= 0; l++, r--) {
            maxval[l] = max(maxval[l - 1], nums[l]);
            minval[r] = min(minval[r + 1], nums[r]);
        }

        for (int i = 0; i < n; i++) {
            int maxm = maxval[i];
            int minm = minval[i];
            int score = maxm - minm;
            if (score <= k) return i;
        }

        return -1;
    }
};
