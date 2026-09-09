public class Solution {
    public long CountCommas(long n) {
        long total = 0;

        for (long threshold = 1000; threshold <= n; threshold *= 1000) {
            total += n - threshold + 1;
        }
        
        return total;
    }
}
