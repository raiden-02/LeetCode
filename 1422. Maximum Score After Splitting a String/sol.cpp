class Solution {
public:
    int maxScore(string s) {
        size_t n = s.length();
        int ans = 0;
        vector<int> left(n), right(n);
        left[0] = s[0] == '0';
        right[n - 1] = s[n - 1] == '1';

        for(int l = 1, r = n - 2; l < n && r >= 0; l++, r--) {
            left[l] = left[l - 1] + (s[l] == '0');
            right[r] = right[r + 1] + (s[r] == '1');
        }

        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, left[i] + right[i + 1]);
        }

        return ans;
    }
};
