class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int pr = mat.size(), pc = mat[0].size();
        if(r * c != pr * pc) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c));
        int pi = 0, pj = 0, i = 0, j = 0;
        
        while(pi < pr and i < r) {
            ans[i][j] = mat[pi][pj];
            pj = (pj + 1) % pc, j = (j + 1) % c;
            
            if(pj == 0) pi++;
            if(j == 0) i++;
        }
        
        return ans;
    }
};
