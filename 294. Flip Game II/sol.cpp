class Solution {
    unordered_map<string, bool> dp;
public:
    bool canWin(string &s) {
        if(dp.find(s) != dp.end())
            return dp[s];
        
        bool ans = false;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == s[i + 1] and s[i] == '+') {
                s[i] = s[i + 1] = '-';
                
                if(not canWin(s)) {
                    ans = true;
                    s[i] = s[i + 1] = '+';
                    break;
                }
                
                s[i] = s[i + 1] = '+';
            }
        }
        
        return dp[s] = ans;
    }
};
