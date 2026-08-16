class Solution {
    static Boolean dp[][];
    static int m, n;
    public static boolean helper(String word, String pattern, int wi, int pi) {

        if(wi == m && pi == n)
            return true;

        if(wi == m) {
            for(int i = pi; i < n; i++) {
                if(pattern.charAt(i) != '*')
                    return false;
            }
            return true;
        }
        
        if(wi != m && pi == n)
            return false;
        
        if(dp[wi][pi] != null)
            return dp[wi][pi];
        
        char c = pattern.charAt(pi);
        
        if((c == '?' || c == word.charAt(wi)) && helper(word, pattern, wi + 1, pi + 1))
            return dp[wi][pi] = true;
        
        if(c == '*') {
            if(helper(word, pattern, wi, pi + 1))
                return dp[wi][pi] = true;
            if(helper(word, pattern, wi + 1, pi))
                return dp[wi][pi] = true;
            if(helper(word, pattern, wi + 1, pi + 1))
                return dp[wi][pi] = true;
        }
        
        return dp[wi][pi] = false;
    }
    
    public boolean isMatch(String s, String p) {
        this.m = s.length();
        this.n = p.length();
        dp = new Boolean[m][n];
        return helper(s, p, 0, 0);
    }
}
