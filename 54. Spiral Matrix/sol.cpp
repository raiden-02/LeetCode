class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0, cnt = 0, lmt = m * n, i = 0;
        bool fr = true, fc = true;
        vector<int> ans(lmt);
        
        while(cnt < lmt) {
            if(fc and fr) {
                while(c < n and matrix[r][c] != 101) ans[i++] = matrix[r][c], matrix[r][c] = 101, c++, cnt++;
                fc = false, c--, r++;
            }
            
            else if(fr and not fc) {
                while(r < m and matrix[r][c] != 101) ans[i++] = matrix[r][c], matrix[r][c] = 101, r++, cnt++;
                fr = false, r--, c--;
            }
            
            else if(not fc and not fr) {
                while(c >= 0 and matrix[r][c] != 101) ans[i++] = matrix[r][c], matrix[r][c] = 101, c--, cnt++;
                fc = true, c++, r--;
            }
            
            else {
                while(r >= 0 and matrix[r][c] != 101) ans[i++] = matrix[r][c], matrix[r][c] = 101, r--, cnt++;
                fr = true, r++, c++;
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size() - 1, n = matrix[0].size(), i = 0, j = -1;
        int c = 0, counter = n, rot = 0;
        pair<int, int> dir = dirs[0];
        vector<int> ans;
        int di = 0;
        
        while(counter) {
            
            for(int k = 0; k < counter; k++) {
                i += dir.first;
                j += dir.second;
                ans.push_back(matrix[i][j]);
            }
            
            if(di % 2 == 0)
                n--;
            else
                m--;
            
            di = (di + 1) % 4;
            dir = dirs[di];
            
            counter = di % 2 == 0 ? n : m;
        }
        
        return ans;
    }
};
