class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s1, s2;
        s += s;
        
        for(int i = 0; i < s.length(); i++) {
            s1 += i % 2 ? '1' : '0';
            s2 += i % 2 ? '0' : '1';
        }
        
        int a = 0, b = 0, ans = INT_MAX;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != s1[i]) a++;
            if(s[i] != s2[i]) b++;
            
            if(i >= n) {
                if(s[i - n] != s1[i - n]) a--;
                if(s[i - n] != s2[i - n]) b--;
            }
            
            if(i >= n - 1)
                ans = min(ans, min(a, b));
        }
        
        return ans;
    }
};
