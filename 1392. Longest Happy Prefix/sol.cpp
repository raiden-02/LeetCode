//lps kmp

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> dp(n);
        
        int i = 0, j = 1;
        
        for(; j < n; j++) {
            if(s[i] == s[j])
                dp[j] = ++i;
            
            else if(i > 0)
                i = dp[i - 1], --j;
        }
        
        return s.substr(0, i);
    }
};
