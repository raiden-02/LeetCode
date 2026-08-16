//min heap intuitive
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({matrix[0][0], 0, 0});
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        
        while(not pq.empty())  {
            auto cur = pq.top(); pq.pop();
            k--;
            int val = cur[0], x = cur[1], y = cur[2];

            if(k == 0) return val;
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;
                
                if(dx >= 0 and dx < m and dy >= 0 and dy < n and not vis[dx][dy])
                    vis[dx][dy] = true, pq.push({matrix[dx][dy], dx, dy});
            }
        }
        
        return -1;
    }
};


//binary search

// --- alternate solution ---

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), l = matrix[0][0], r = matrix[m - 1][n - 1];
        
        while(l < r) {
            int mid = (l + r) >> 1;
            int steps = 0;
            
            for(auto &x : matrix)
                steps += (upper_bound(x.begin(), x.end(), mid) - x.begin());
            
            if(steps < k)
                l = mid + 1;
            else
                r = mid;
        }
        
        return l;
    }
};
