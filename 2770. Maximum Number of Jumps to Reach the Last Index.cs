public class Solution {
    int MemoizedJump (int[] nums, int[] memo, int ind, int target) {
        if (ind >= nums.Length) {
            return int.MinValue;
        }

        if (ind == nums.Length - 1) {
            return 0;
        }

        if (memo[ind] != int.MinValue) {
            return memo[ind];
        }

        int ans = int.MinValue;

        for (int i = ind + 1; i < nums.Length; i++) {
            if (Math.Abs(nums[i] - nums[ind]) <= target) {
                ans = Math.Max(ans, 1 + MemoizedJump(nums, memo, i, target));
            }
        }

        memo[ind] = ans;
        return ans;
    }
    public int MaximumJumps(int[] nums, int target) {
        int[] memo = new int[nums.Length];
        Array.Fill(memo, int.MinValue);
        int ans = MemoizedJump(nums, memo, 0, target);
        return ans <= 0 ? -1 : ans;
    }
}
