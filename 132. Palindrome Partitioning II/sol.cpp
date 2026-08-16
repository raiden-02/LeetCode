class Solution {
    int dp[2001];

    bool isPalindrome(string const& tmp) {
        for(int l = 0, r = tmp.length() - 1; l <= r; l++, r--)
            if(tmp[l] != tmp[r]) return false;
        
        return true;
    }

    int helper(string const& s, int ind) {
        if(ind >= s.length()) {
            return 0;
        }

        if(dp[ind] != -1)
            return dp[ind];

        string tmp;
        int ans = INT_MAX / 2;

        for(int i = ind; i < s.length(); i++) {
            tmp += s[i];

            if(isPalindrome(tmp))
                ans = min(ans, helper(s, i + 1) + 1);
        }

        return dp[ind] = ans;
    }
public:
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0) - 1;
    }
};
