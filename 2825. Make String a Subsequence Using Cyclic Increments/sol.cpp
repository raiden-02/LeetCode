class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        size_t m = str1.length(), n = str2.length();
        size_t j = 0;

        for(size_t i = 0; i < m && j < n; i++) {
            if(str1[i] == str2[j] || ((str1[i] - 'a' + 1) % 26 + 'a') == str2[j]) {
                j++;
            }
        }

        return j == n;
    }
};
