class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int n1 = 1, n2 = 1, n3 = 0, nn = 0;

        for(int i = 3; i <= n; i++) {
            nn = n1 + n2 + n3;
            int t1 = n1, t2 = n2;

            n1 = nn, n2 = t1, n3 = t2;
        }

        return nn;
    }
};

// --- alternate solution ---

class Solution {
public:
    int tribonacci(int n) {
        if(n < 3)
            return n == 0 ? 0 : 1;
        
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        
        return dp[n];
    }
};
