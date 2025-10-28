public class Solution {
    public int CountValidSelections(int[] nums) {
        int n = nums.Length;
        int ans = 0;

        int totalNeeded = 0;
        for (int i = 0; i < n; i++) totalNeeded += nums[i];

        int Traverse(int dir, int start) {
           
            var a = (int[])nums.Clone();
            int remaining = totalNeeded;
            int cur = start;

            while (true) {
                cur += dir;
                if ((uint)cur >= (uint)a.Length) break;

                if (a[cur] > 0) {
                    a[cur]--;
                    remaining--;
                    dir = -dir;
                    if (remaining == 0) return 1;
                }
            }
            return remaining == 0 ? 1 : 0;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans += Traverse(1, i);
                ans += Traverse(-1, i);
            }
        }
        return ans;
    }
}
