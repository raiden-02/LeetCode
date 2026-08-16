class Solution {
    int dp[501];

    int helper(vector<int> const& arr, int ind, int const& k){
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        int maxm = arr[ind];
        int ans = 0;

        for(int i = ind; i < arr.size() && i - ind + 1 <= k; i++) {
            int size = i - ind + 1;
            maxm = max(maxm, arr[i]);
            int s = maxm * size + helper(arr, i + 1, k);
            ans = max(ans, s);
        }

        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, k);
    }
};
