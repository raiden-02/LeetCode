class Solution {
    int dp[100][100][200];

    bool helper(string const& s1, string const& s2, string const& s3, int i, int j, int k) {
        if(i == s1.length()) return s2.substr(j) == s3.substr(k);
        if(j == s2.length()) return s1.substr(i) == s3.substr(k);
        if(k == s3.length()) return false;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool ans = false;

        if(s1[i] == s3[k]) ans |= helper(s1, s2, s3, i + 1, j, k + 1);
        if(s2[j] == s3[k]) ans |= helper(s1, s2, s3, i, j + 1, k + 1);

        return dp[i][j][k] = ans; 
    } 
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
