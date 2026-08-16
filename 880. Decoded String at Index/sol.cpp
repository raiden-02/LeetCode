class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long len = 0;

        for(char x : s) {
            if(isdigit(x)) {
                len *= x - '0';
            }

            else {
                len++;
            }
        }

        for(int i = s.length() - 1; i >= 0; i--) {
            k %= len;

            if(k == 0 && isalpha(s[i])) {
                return  (string)"" + s[i];
            }

            if(isdigit(s[i])) {
                len /= s[i] - '0';
            }
            else {
                len--;
            }
        }

        return "";
    }
};
