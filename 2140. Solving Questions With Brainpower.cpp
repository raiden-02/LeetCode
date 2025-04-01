#define ll long long
class Solution {
    ll helper(vector<vector<int>> const& arr, int ind, vector<ll> &dp) {
        if(ind >= arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        ll a = helper(arr, ind + arr[ind][1] + 1, dp) + arr[ind][0];
        ll b = helper(arr, ind + 1, dp);
        ll ans = max(a, b);

        return dp[ind] = ans;
    }
public:
    ll mostPoints(vector<vector<int>>& questions) {
        vector<ll> dp(questions.size(), -1);
        return helper(questions, 0, dp);
    }
};
