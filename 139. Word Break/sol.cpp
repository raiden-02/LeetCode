class Solution {
    unordered_map<string, bool> dp;
    
    bool helper(string s, unordered_set<string> const& words) {
        if(words.find(s) != words.end()) return true;
        
        if(dp.find(s) != dp.end()) return dp[s];
        
        for(int i = 0; i < s.length(); i++) {
            if(words.find(s.substr(0, i + 1)) != words.end() and helper(s.substr(i + 1), words)) {
                dp[s] = true;
                return true;
            }
        }
        
        return dp[s] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return helper(s, words);
    }
};
