public class Solution {
    public int BinaryGap(int n) {
        int count = -1, ans = 0;

        while (n > 0) {
            int is_right_most_1 = n & 1;
            
            if (is_right_most_1 == 1) {
                if (count != 0)
                    ans = Math.Max(ans, count);
                count = 0;
            }

            n >>= 1;
            if (count != -1) count++;
        }

        return ans;
    }
}
