class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), l = 0, r = n - 1;

        while(l < r && s[l] == s[r]) {
            char c = s[l];
            while(l < r && s[l] == c) l++;

            if(l >= r) return 0;

            while(l < r && s[r] == c) r--;
        }

        return r - l + 1;
    }
};
