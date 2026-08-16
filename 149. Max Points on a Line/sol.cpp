class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, vector<pair<int, int>>> slopes;
        int ans = 1;
        sort(points.begin(), points.end());

        for(int i = 0; i < points.size(); i++) {
            double x1 = points[i][0], y1 = points[i][1];

            for(int j = i + 1; j < points.size(); j++) {
                double x2 = points[j][0], y2 = points[j][1];

                double slope = (y2 - y1) / (x2 - x1);                
                slopes[slope].push_back({i, j});
            }
        }

        for(auto &[slope, indpairs] : slopes) {
            for(int i = 0; i < indpairs.size(); i++) {
                if(indpairs[i].first == -1) continue;

                int prevSecondInd = indpairs[i].second, len = 1;
                indpairs[i] = {-1, -1};

                for(int j = i + 1; j < indpairs.size(); j++) {
                    if(indpairs[j].first == -1) continue;
                    
                    int curFirstInd = indpairs[j].first;
                    int curSecondInd = indpairs[j].second;

                    if(prevSecondInd == curFirstInd)
                        len++, prevSecondInd = curSecondInd, indpairs[j] = {-1, -1};
                }

                ans = max(ans, len + 1);
            }
        }

        return ans;        
    }
};

// --- alternate solution ---

class Solution {
    double INF = 1e9 + 7;
    
    double slope(vector<int> const& a, vector<int> const& b) {
        double dy = b[1] - a[1];
        double dx = b[0] - a[0];
        
        return not dx ? INF : dy / dx; 
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        unordered_map<double, int> mp;
        
        for(int i = 0; i < n; i++) {
            auto cur = points[i];
            int same = 0;
            vector<double> angles;
            mp.clear();
            
            for(int j = i + 1; j < n; j++) {
                auto next = points[j];

                cur == next ? same += 1 : (angles.push_back(slope(cur, next)), mp[angles.back()]++);
            }
            
            int maxslopes = 0;
            
            for(auto &x : mp)
                maxslopes = max(maxslopes, x.second);
            
            ans = max(ans, maxslopes + same + 1);
        }
        
        return ans;
    }
};
