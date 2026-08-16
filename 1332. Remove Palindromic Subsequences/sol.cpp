class Solution {
public:
    int removePalindromeSub(string s) {
        int l = 0, r = s.length() - 1;
        
        while(l <= r) {
            if(s[l] == s[r])
                l++, r--;
            
            else
                return 2;
        }
        
        return 1;
    }
};

// --- alternate solution ---

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;
        
        string sr = s;
        reverse(sr.begin(), sr.end());
        if(s == sr)
            return 1;
        
        return 2;
    }
};
