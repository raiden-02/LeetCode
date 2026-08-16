class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ind = 0;
        
        for(int i = m - 1; i >=0; i--) {
            vector<int> tmp;
            int row = i, col = 0;
            
            while(row < m and col < n)
                tmp.push_back(mat[row++][col++]);
            
            sort(tmp.begin(), tmp.end());
            row = i, col = 0;
            int cind = 0;
            
            while(row < m and col < n and cind < tmp.size())
                mat[row++][col++] = tmp[cind++];
        }
        
        for(int j = 0; j < n; j++) {
            vector<int> tmp;
            int row = 0, col = j;
            
            while(row < m and col < n)
                tmp.push_back(mat[row++][col++]);
            
            sort(tmp.begin(), tmp.end());
            row = 0, col = j;
            int cind = 0;
            
            while(row < m and col < n and cind < tmp.size())
                mat[row++][col++] = tmp[cind++];
        }
        
        return mat;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int r = i, c = j;
                //cout << "start: " << r << " " << c << endl;
                vector<int> tmp;
                while(r < m && c < n) {
                    //cout << r << " " << c << ", ";
                    tmp.push_back(mat[r][c]);
                    r += 1;
                    c += 1;
                }
                //cout << "here " <<endl;
                r = i, c = j;
                sort(tmp.begin(), tmp.end());
                int k = 0;
                while(r < m && c < n && k < tmp.size()) {
                    mat[r][c] = tmp[k];
                    r += 1;
                    c += 1;
                    k += 1;
                }
            }
        }
        return mat;
    }
};
