class Solution {
    int helper(string &s, int l, int r) {
        int ans = 0;
        if(s[l] == s[r])
            return ans;
        
        char pl = s[l], pr = s[r];
        
        while(l >= 0 && r < s.length() && s[l] == pl && s[r] == pr) {
            ans++;
            l--, r++;
        }
        
        return ans;
    }
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            ans += helper(s, i, i + 1);
        }
        
        return ans;
    }
};
