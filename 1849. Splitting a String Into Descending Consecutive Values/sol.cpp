class Solution {
    bool helper(string &s, int ind, long prev, int c) {
        if(ind == s.length())
            return c > 1;
        
        long num = 0;
        bool ans = false;
        
        for(int i = ind; i < s.length() and num < INT_MAX; i++) {
            num = num * 10 + (s[i] - '0');
            
            if(prev - 1 == num or prev == -1)
                ans = ans or helper(s, i + 1, num, c + 1);
            
            if(ans) break;
        }
        
        return ans;
    }
public:
    bool splitString(string s) {
        return helper(s, 0, -1, 0);
    }
};
