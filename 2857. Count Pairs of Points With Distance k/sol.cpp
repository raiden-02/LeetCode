class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 0;

        for(auto &coord : coordinates) {
            int x1 = coord[0], y1 = coord[1];
            
            for(int x = 0; x <= k; x++) {
                int y = k - x;
                if(mp[x1 ^ x].count(y1 ^ y)) {
                    ans += mp[x1 ^ x][y1 ^ y];
                }
            }

            mp[x1][y1]++;
        }

        return ans;
    }
};
