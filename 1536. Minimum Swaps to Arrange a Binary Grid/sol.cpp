class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<int> keys(n);
        
        for(int i = 0; i < n; i++) {
            auto ind = find(grid[i].rbegin(), grid[i].rend(), 1);
            
            if(ind != grid[i].rend()) keys[i] = n - (ind - grid[i].rbegin()) - 1;
        }
        
        for(int i = 0; i < n; i++) {
            bool f = true;
            
            for(int j = 0; j < keys.size(); j++) {
                if(keys[j] <= i) {
                    f = false;
                    keys.erase(keys.begin() + j), ans += j;
                    break;
                }
            }
            
            if(f) return -1;
        }
        
        return ans;
    }
};
