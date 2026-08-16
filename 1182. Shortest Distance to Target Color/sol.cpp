class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(4, vector<int>(n, -1)));
        int left = 0, right = 1;
        
        for(int color = 1; color <= 3; color++) {
            if(colors[0] == color)
                dp[left][color][0] = 0;
            
            if(colors[n - 1] == color)
                dp[right][color][n - 1] = 0;
            
            for(int i = 1; i < n; i++) {
                if(dp[left][color][i - 1] != -1)
                    dp[left][color][i] = dp[left][color][i - 1] + 1;
                
                if(colors[i] == color)
                    dp[left][color][i] = 0;
            }
            
            for(int i = n - 2; i >= 0; i--) {
                if(dp[right][color][i + 1] != -1)
                    dp[right][color][i] = dp[right][color][i + 1] + 1;
                
                if(colors[i] == color)
                    dp[right][color][i] = 0;
            }
        }
        
        int m = queries.size();
        vector<int> ans(m, -1);
        
        for(int i = 0; i < m; i++) {
            int ind = queries[i][0], color = queries[i][1];
            
            int l = dp[left][color][ind];
            int r = dp[right][color][ind];
            
            int d = l == -1 or r == -1 ? max(l, r) : min(l, r);
            
            ans[i] = d;
        }
        
        return ans;
    }
};
