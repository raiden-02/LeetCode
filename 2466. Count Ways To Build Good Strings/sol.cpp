class Solution {
    static const int N = 1e5 + 1;
    int dp[N];
    int ans = 0;
    const int MOD = 1e9 + 7;

    int helper(int const& zero, int const& one, int const& low, int const& high, int len) {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];

        int ans = helper(zero, one, low, high, len + zero) + helper(zero, one, low, high, len + one);

        if(len + zero <= high && len + zero >= low)
            ans += 1;
        if(len + one <= high && len + one >= low)
            ans += 1;

        return dp[len] = ans % MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return helper(zero, one, low, high, 0);
    }
};
