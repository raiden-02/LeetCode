class Solution {
    const int MOD = 1e9 + 7;
    int dp[31][1001];

    int helper(int n, int target, int const& k) {
        if(n == 0 && target == 0) return 1;

        if(n <= 0 || target <= 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        long ans = 0;

        for(int i = k; i > 0; i--) {
            ans = (ans + helper(n - 1, target - i, k)) % MOD;
        }

        return  dp[n][target] = ans % MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(n, target, k);
    }
};
