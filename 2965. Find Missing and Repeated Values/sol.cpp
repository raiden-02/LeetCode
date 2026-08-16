class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mem(n * n, 0);
        int a = -1, b = -1;

        for(auto &x : grid) {
            for(int y : x) {
                mem[y - 1] += 1;
                if(mem[y - 1] > 1) a = y;
            }
        }

        for(int i = 0; i < n * n; i++) if(mem[i] == 0) b = i + 1;

        return {a, b};
    }
};
