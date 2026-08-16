class Solution {
    int helper(string &s) {
        int ans = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                ans += 1;
                s[i] = s[i - 1] == '0' ? '1' : '0';
            }
        }
        return ans;
    }
public:
    int minOperations(string s) {
        string a = s, b = s;
        int c1 = a[0] == '1' ? 1 : 0;
        int c2 = b[0] == '0' ? 1 : 0;
        a[0] = '0';
        b[0] = '1';
        return min(c1 + helper(a), c2 + helper(b));
    }
};

// --- alternate solution ---

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                cnt1 += s[i] == '1';
                cnt2 += s[i] == '0';
            }

            else {
                cnt1 += s[i] == '0';
                cnt2 += s[i] == '1';
            }
        }

        return min(cnt1, cnt2);
    }
};
