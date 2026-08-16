class Solution {
    int ans = INT_MAX, diff = INT_MAX;
    unordered_set<int> dp[11];

    void helper(vector<int> const& costs, int ind, int const& target, int cost) {
        int curd = abs(cost - target);

        if(cost > ans and curd > diff) return;

        if(ind >= costs.size()) {
            if(curd <= diff) {
                if(curd == diff) ans = min(ans, cost);
                else ans = cost;
                diff = curd;
            }

            return;
        }

        if(dp[ind].count(cost)) return;

        helper(costs, ind + 1, target, cost);
        helper(costs, ind + 1, target, cost + 2 * costs[ind]);
        helper(costs, ind + 1, target, cost + costs[ind]);
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for(int x : baseCosts)
            helper(toppingCosts, 0, target, x);

        return ans;
    }
};
