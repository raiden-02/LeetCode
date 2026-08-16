class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int ans = 0, e = INT_MIN;
        
        for(auto &x : points) {
            if(x[0] > e)
                ans++, e = x[1];
            
            else
                e = min(e, x[1]);
        }
        
        return ans == 0 ? !points.empty() : ans;
    }
};
