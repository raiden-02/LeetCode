class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mn = INT_MAX;
                
                for(int k = 0; k < m; k++) {
                    if(j == k) continue;
                    mn = min(costs[i - 1][k], mn);
                }
                
                costs[i][j] += mn;
            }
        }
        
        return *min_element(costs[n - 1].begin(), costs[n - 1].end());
    }
};
