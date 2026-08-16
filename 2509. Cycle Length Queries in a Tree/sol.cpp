class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 1);

        for(int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];

            while(a != b) {
                a > b ? a /= 2 : b /= 2;
                ans[i]++;
            }
        }

        return ans;
    }
};
