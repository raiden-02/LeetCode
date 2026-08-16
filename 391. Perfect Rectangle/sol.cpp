class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        
        for(auto &x : rectangles) {
            mp[{x[0], x[1]}]++;
            mp[{x[0], x[3]}]--;
            mp[{x[2], x[3]}]++;
            mp[{x[2], x[1]}]--;
        }
        
        int ans = 0;
        for(auto &x : mp) ans += abs(x.second);
        
        return ans == 4;
    }
};
