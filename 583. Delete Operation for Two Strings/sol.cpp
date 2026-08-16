class Solution {
    vector<vector<int>> dp;
    int helper(string &s1, string &s2, int i, int j) {
        if(i == s1.length() or j == s2.length())
            return max(s1.length() - i, s2.length() - j);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = helper(s1, s2, i + 1, j + 1);
        
        return dp[i][j] = min(helper(s1, s2, i + 1, j), helper(s1, s2, i, j + 1)) + 1;
    }
public:
    int minDistance(string word1, string word2) {
        dp.resize(word1.length(), vector<int>(word2.length(), -1));
        return helper(word1, word2, 0, 0);
    }
};
