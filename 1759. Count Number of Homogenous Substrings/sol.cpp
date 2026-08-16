class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0, len = 1;
        const int MOD = 1e9 + 7;
        char prev = '*';

        for(char x : s) {
            len = x == prev ? len + 1 : 1;
            ans = (ans + len) % MOD;
            prev = x;
        }

        return ans;
    }
};
