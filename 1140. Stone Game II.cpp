class Solution {
    vector<vector<int>> dp;
    int helper(vector<int> const& piles, int m, int ind) {
        if (ind >= piles.size()) return 0;

        if (dp[m][ind] != -1) return dp[m][ind];

        int s = 0, ans = INT_MIN;

        for (int i = ind; i < min((int)piles.size(), ind + 2 * m); i++) {
            s += piles[i];
            ans = max(ans, s - helper(piles, max(i - ind + 1, m), i + 1));
        }

        return dp[m][ind] = ans;
    }
public: 
    int stoneGameII(vector<int>& piles) {
        int m = piles.size();
        dp.resize(2 * m + 1, vector<int>(m, -1));
        int diff = helper(piles, 1, 0); // alice - bob
        int total = accumulate(piles.begin(), piles.end(), 0); // alice + bob
        return (total + diff) / 2;
    }
};



// bottom up iterative
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n);
        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];

        // dp[i][m] = max stones current player can get
        vector<vector<int>> dp(n, vector<int>(n + 1));

        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                for (int x = 1; x <= 2 * m; x++) {
                    int opponent = dp[i + x][max(m, x)];

                    dp[i][m] = max(dp[i][m], suffix[i] - opponent);
                }
            }
        }

        return dp[0][1];
    }
};
