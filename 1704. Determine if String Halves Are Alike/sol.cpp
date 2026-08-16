class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length(), half = n / 2;
        int r = n % 2 ? half + 1 : half, lc = 0, rc = 0;
        
        auto isVowel = [](char x) {
            x = tolower(x);
            return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
        };
        
        for(int l = 0; l < half and r < n; l++, r++) {
            if(isVowel(s[l])) lc++;
            if(isVowel(s[r])) rc++;
        }
        
        return lc == rc;
    }
};
