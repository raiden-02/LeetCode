class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2);

        for (int s = 0, l = n - 1; s < l; s++, l--) {
            int a = nums[s];
            int b = nums[l];

            int lo = min(a, b), hi = max(a, b);
            int sum = a + b;

            // Start with 2 moves for every target sum
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // This pair needs only 1 move in this range
            diff[lo + 1] -= 1;
            diff[hi + limit + 1] += 1;

            // This exact sum needs 0 moves
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = numeric_limits<int>::max();
        int cur = 0;

        for (int x = 2; x <= 2 * limit; x++) {
            cur += diff[x];
            ans = min(ans, cur);
        }

        return ans; 
    }
};
