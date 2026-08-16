class Solution {
    public int minStartValue(int[] nums) {
        int s = 0, ans = Integer.MAX_VALUE;
        
        for(int x : nums) {
            s += x;
            ans = Math.min(ans, s);
        }
        
        return ans >= 0 ? 1 : Math.abs(ans - 1);
    }
}
