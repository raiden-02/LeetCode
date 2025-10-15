class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> l(n), r(n);
        l[0] = 1, r[n - 1] = 1;
        int ans = 0;

        for(size_t i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
            l[i] = nums[i] > nums[i - 1] ? l[i - 1] + 1 : 1;
            r[j] = nums[j] < nums[j + 1] ? r[j + 1] + 1 : 1;
        }

        for(size_t i = 0; i < n - 1; i++) {
            ans = max(ans, min(l[i], r[i + 1]));
        }

        return ans;
    }
};
