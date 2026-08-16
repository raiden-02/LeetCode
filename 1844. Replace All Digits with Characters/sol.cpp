class Solution {
public:
    string replaceDigits(string s) {
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] >= '0' and s[i] <= '9') {
                s[i] = ((s[i - 1] - 'a') + (s[i] - '0')) % 26 + 'a';
            }
        }
        
        return s;
    }
};
