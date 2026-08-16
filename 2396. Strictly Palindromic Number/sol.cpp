class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n - 2; i++) {
            string s;
            int num = n;
            while(num) {
                int rem = num % i;
                s.push_back(char(rem + '0'));
                num /= i;
            }

            while(s.length() % i)
                s.push_back('0');
            
            for(int l = 0, r = s.length() - 1; l <= r; l++, r--)
                if(s[l] != s[r]) return false;
        }

        return true;
    }
};
