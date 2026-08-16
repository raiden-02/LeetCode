class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        size_t n = costs.size();
        int ans = 0;

        for(size_t l = 0, r = n / 2; l < n / 2 && r < n; l++, r++) {
            ans += costs[l][0] + costs[r][1];
        }

        return ans;
    }
};
