class Solution {
    int paths[10][10] = {0};
    bool vis[10] = {0};
    
    int helper(int num, int size) {
        if(size == 0)
            return 1;
        
        int ans = 0;
        
        for(int neigh = 1; neigh <= 9; neigh++) {
            if(!vis[neigh] and (!paths[num][neigh] or vis[paths[num][neigh]])) {
                vis[neigh] = true;
                ans += helper(neigh, size - 1);
                vis[neigh] = false;
        }
        
        return ans;
    }
public:
    int numberOfPatterns(int m, int n) {
        paths[1][9] = paths[9][1] = paths[2][8] = paths[8][2] = paths[3][7] = paths[7][3] = paths[4][6] = paths[6][4] = 5, paths[1][3] = paths[3][1] = 2, paths[1][7] = paths[7][1] = 4, paths[3][9] = paths[9][3] = 6, paths[7][9] = paths[9][7] = 8;
        
        int ans = 0;
        
        for(int i = m; i <= n; i++) {
            for(int const& x : {1, 2, 5}) {
                vis[x] = true;
                
                int counter = helper(x, i - 1);
                ans = ans + (x == 5 ? counter : counter * 4);
                
                vis[x] = false;
            }
        }
        
        return ans;
    }
};
