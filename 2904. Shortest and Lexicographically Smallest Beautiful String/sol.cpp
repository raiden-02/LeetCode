class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ones = 0, l = 0;
        int bestLen = INT_MAX;
        string ans;

        for (int r = 0; r < n; r++) {
            ones += s[r] - '0';

            while (l <= r && ones > k) {
                ones -= s[l] - '0';
                l++;
            }

            // remove unnecessary 0s
            while (l <= r && ones == k && s[l] == '0') {
                l++;
            }

            if (ones == k) {
                int len = r - l + 1;

                if (len < bestLen) {
                    bestLen = len;
                    ans = s.substr(l, len);
                }
                else if (len == bestLen &&
                         s.compare(l, len, ans) < 0) {
                    ans = s.substr(l, len);
                }
            }
        }

        return ans;
    }
};
