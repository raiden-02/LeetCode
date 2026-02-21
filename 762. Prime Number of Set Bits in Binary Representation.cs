public class Solution {
    public int CountPrimeSetBits(int left, int right) {
        int ans = 0;
        
        for (int i = left; i <= right; i++) {
            int num = i;
            int count = 0;
            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }

            ans = (count == 2 || count == 3 || count == 5 || count == 7 || count == 11 || count == 13 || count == 17 || count == 19) ? ans + 1 : ans;  
        }

        return ans;
    }
}
