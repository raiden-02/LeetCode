class Solution {
    int MOD = 1e9 + 7;
    int dp[52][101][52];
    int m, n, k;

    int helper(int ind, int curMax, int cnt) {
        if(ind == n) {
            if(cnt == k) return 1;
            return 0;
        }

        if(cnt > k) return 0;

        if(dp[ind][curMax][cnt] != -1)
            return dp[ind][curMax][cnt];

        int ans = 0;

        for(int x = 1; x <= curMax; x++) {
            ans = (ans + helper(ind + 1, curMax, cnt)) % MOD;
        }

        for(int x = curMax + 1; x <= m; x++) {
            ans = (ans + helper(ind + 1, x, cnt + 1)) % MOD;
        }

        return dp[ind][curMax][cnt] = ans;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        this->m = m;
        this->n = n;
        this->k = k;

        return helper(0, 0, 0);
    }
};
