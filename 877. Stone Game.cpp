class Solution {
    int max_diff(vector<int> const& piles, vector<vector<int>> &dp, int l, int r) {
        if (l == r) return piles[l];
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = max(piles[l] - max_diff(piles, dp, l + 1, r), piles[r] - max_diff(piles, dp, l, r - 1));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return max_diff(piles, dp, 0, n - 1) > 0; 
    }
};
