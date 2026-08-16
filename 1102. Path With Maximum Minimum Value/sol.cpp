class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        //score is the minimum value in a path
        //we have to find out the max score among all paths
        //djikstra max heap priority queue
        
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        dp[0][0] = A[0][0];
        
        set<pair<int, int>> vis;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<vector<int>> pq;
        pq.push({A[0][0], 0, 0});
        
        auto bound = [&](int &x, int &y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        while(!pq.empty()) {
            int max_score = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            vis.insert(make_pair(i, j));
            pq.pop();
            
            for(auto &dir : dirs) {
                int di = dir.first + i, dj = dir.second + j;
                
                if(bound(di, dj) && vis.find(make_pair(di, dj)) == vis.end()) {
                    int cur_min_score = min(max_score, A[di][dj]);
                    if(cur_min_score > dp[di][dj]) {
                        dp[di][dj] = cur_min_score;
                        pq.push({cur_min_score, di, dj});
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
        
    }
};
