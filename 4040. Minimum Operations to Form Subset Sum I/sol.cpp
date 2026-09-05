class Solution {
    static constexpr int INF = 1e9;

    vector<vector<pair<int, int>>> choices;
    vector<vector<int>> memo;
    int n;

    int dfs(int i, int remaining) {
        if (remaining == 0) return 0;
        if (i == n) return INF;

        int &ans = memo[i][remaining];

        if (ans != -1) return ans;

        // choice 1: do not include nums[i]
        ans = dfs(i + 1, remaining);

        // choice 2: transform and include nums[i]
        for (auto &[value, operations] : choices[i]) {
            if (value <= remaining) {
                int next = dfs(i + 1, remaining - value);

                if (next != INF) {
                    ans = min(ans, operations + next);
                }
            }
        }

        return ans;
    }
public:
    int minOperations(vector<int>& nums, int target) {
        n = nums.size();
        choices.resize(n);

        for (int i = 0; i < n; i++) {
            long long x = nums[i];

            if (x == 0) {
                continue; // Selecting zero never helps.
            }

            // Use unchanged or multiply by 2 repeatedly.
            long long value = x;
            int operations = 0;

            while (value <= target) {
                choices[i].push_back({
                    static_cast<int>(value),
                    operations
                });

                if (value > target / 2) {
                    break; // Avoid overflow and values above target.
                }

                value *= 2;
                operations++;
            }

            // Divide by 2 repeatedly.
            value = x / 2;
            operations = 1;

            while (value > 0) {
                if (value <= target) {
                    choices[i].push_back({
                        static_cast<int>(value),
                        operations
                    });
                }

                value /= 2;
                operations++;
            }
        }

        memo.assign(n, vector<int>(target + 1, -1));

        int answer = dfs(0, target);
        return answer == INF ? -1 : answer;
    }
};
