class Solution {
    vector<int> memo;
    static constexpr int MOD = 1e9 + 7; 

    int helper(string const& s, int ind) {
        if (ind >= s.length()) {
            return 0;
        }

        if (memo[ind] != -1) return memo[ind];
        
        int ans = 0;
        array<bool, 26> vis{false};

        for (int i = ind; i < s.length(); i++) {
            int c = s[i] - 'a';

            if (vis[c]) continue;
            vis[c] = true;

            ans = (ans + 1 + helper(s, i + 1)) % MOD;
        }

        return memo[ind] = ans;
    }
public:
    int distinctSubseqII(string s) {
        memo.resize(s.length(), -1);
        return helper(s, 0);
    }
};
