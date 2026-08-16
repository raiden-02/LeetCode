class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        size_t n = s.length(), m = spaces.size();
        string ans(n + m, ' ');
        size_t ind = 0;

        for(size_t i = 0, j = 0; i < n && j < n + m; j++) {
            if(ind < m && spaces[ind] == i) {
                ans[j] = ' ';
                ind++;
            }

            else {
                ans[j] = s[i];
                i++;
            }
        }

        return ans;
    }
};
