class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string ans(n, '0');
        int cnt = 0;
        
        for(char x : s) {
            cnt += x == '1';
        }
        
        ans[n - 1] = '1';
        cnt--;
        
        for(int i = 0; i < n - 1 && cnt; i++) {
            ans[i] = '1';
            cnt--;
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0, n = s.length();

        for(char x : s)
            cnt += x == '1';

        for(int i = 0; i < n; i++) {
            if(i == n - 1 || cnt > 1) s[i] = '1', cnt--;
            else s[i] = '0';
        }

        return s;
    }
};
