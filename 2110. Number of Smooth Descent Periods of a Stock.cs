public class Solution {
    public long GetDescentPeriods(int[] prices) {
        long ans = 1, len = 1;

        for (int r = 1, l = 0; r < prices.Length; r++) {
            if (prices[r - 1] == prices[r] + 1) {
                len++;
            }

            else {
                len = 1;
            }

            ans += len;
        }

        return ans;
    }
}
