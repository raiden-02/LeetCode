class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        vector<pair<int, int>> ones1, ones2;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> mp;
        
        for(auto &x : ones1) {
            for(auto &y : ones2) {
                int dy = y.second - x.second, dx = y.first - x.first;
                ans = max(ans, ++mp[{dx, dy}]);
            }
        }
        
        return ans;
    }
};
