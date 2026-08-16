class Solution {
    pair<int, string> helper(string const& s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r])
            l--, r++;
        
        return {r - l - 1, s.substr(l + 1, r - l - 1)};
    }
public:
    string longestPalindrome(string s) {
        pair<int, string> ans = {0, ""};
        for(int i = 0; i < s.length(); i++) {
            auto even = helper(s, i, i + 1);
            auto odd = helper(s, i, i);
            ans = max(ans, max(even, odd));
        }
        
        return ans.second;
    }
};
