class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> vis;
        
        for(auto &x : nums) {
            for(int y = x[0]; y <= x[1]; y++) {
                if(vis.count(y)) continue;
                vis.insert(y);
            }
        }
        
        return (int)vis.size();
    }
};
