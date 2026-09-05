class Solution {
    static constexpr int INF = 1e9;
    int n;
    vector<vector<pair<int, int>>> choices; 
    vector<vector<int>> memo;
    
    int dfs(int i, int remaining) {
        if (remaining == 0) return 0;
        if (i >= n) return INF;

        int &ans = memo[i][remaining];
        
        if (ans != -1) return ans;

        ans = dfs(i + 1, remaining);

        for (auto &[value, operations] : choices[i]) {
            if (value > remaining) continue;
            
            int next = dfs(i + 1, remaining - value);

            if (next != INF) 
                ans = min(ans, operations + next);
        }

        return memo[i][remaining] = ans;
    }
public:
    int minOperations(vector<int>& nums, int target) {
        n = nums.size();
        memo.resize(n, vector<int>(target + 1, -1));
        choices.resize(n);

        for (int i = 0; i < n; i++) {
            int divops = 0;
            int divval = nums[i];

            while (divval > 0) {
                int val = divval;
                int mulops = 0;

                while (val <= target) {
                    choices[i].push_back({val, divops + mulops});

                    if (val > target / 2) break;

                    val *= 2;
                    mulops++;
                }

                divval /= 2;
                divops++;
            }
        }

        int ans = dfs(0, target);
        return ans == INF ? -1 : ans;
    }
};
