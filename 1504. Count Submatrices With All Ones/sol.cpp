class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        for(int i = 0; i < m; i++) for(int j = 1; j < n; j++) if(mat[i][j]) mat[i][j] += mat[i][j - 1];
        
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(not mat[i][j]) continue;
                
                int minl = n + 1;
                
                for(int k = i; k < m; k++)
                    minl = min(minl, mat[k][j]), ans += minl;
            }
        }
        
        return ans;
    }
};
