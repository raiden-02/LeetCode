class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), ans = 0;

        for(int j = 0; j < n; j++) {
            for(int i = 1; i < m; i++) {
                if(strs[i - 1][j] > strs[i][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
