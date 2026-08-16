class Solution {
    vector<vector<int>> dp;
    int helper(string const& word1, string const& word2, int i, int j, int const& m, int const& n) {
        if(i == m && j == n)
            return 0;
        
        if(i == m) return n - j; //insert these many characters at the end of the other implies cost = length of string - current index
        if(j == n) return m - i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, i + 1, j + 1, m, n);
        
        return dp[i][j] = min(helper(word1, word2, i + 1, j + 1, m, n), min(helper(word1, word2, i + 1, j, m, n), helper(word1, word2, i, j + 1, m, n))) + 1;
    }
public:
    int minDistance(string word1, string word2) {
        if(word2.length() > word1.length())
            return minDistance(word2, word1);
        
        dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
        return helper(word1, word2, 0, 0, word1.length(), word2.length());
    }
};
