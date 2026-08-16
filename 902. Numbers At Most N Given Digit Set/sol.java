class Solution {
    public int atMostNGivenDigitSet(String[] digits, int N) {
        String num = String.valueOf(N);
        int len = digits.length, n = num.length();
        int ans = 0;
        
        for(int i = 1; i < n; i++)
            ans += Math.pow(len, i);
        
        int[] dp = new int[n];
        
        for(int i = n - 1; i >= 0; i--) {
            
            for(String digit : digits) {
                if(digit.charAt(0) < num.charAt(i))
                    dp[i] += Math.pow(len, n - i - 1);
                
                else if(digit.charAt(0) == num.charAt(i))
                    dp[i] += (i < n - 1) ? dp[i + 1] : 1;
            }
        }
        
        return dp[0] + ans;
    }
}
