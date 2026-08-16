class Solution {
    int helper(string const& s, int l, int r) {
        int ans = 0;
        while(l >= 0 && r < s.length() && s[l--] == s[r++])
            ans++;
        
        return ans;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            int even = helper(s, i, i + 1);
            int odd = helper(s, i, i);
            ans += (even + odd); 
        }
        return ans;
    }
};
