class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size(), n = picture[0].size();
        vector<vector<int>> rc(m, vector<int>(2)), cc(n, vector<int>(2));
        vector<vector<int>> rowsB(n);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] == 'W') rc[i][0]++, cc[j][0]++; 
                else rc[i][1]++, cc[j][1]++, rowsB[j].push_back(i);
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] == 'B') {
                    if(rc[i][1] == target and cc[j][1] == target) {
                        bool f = true;
                        
                        for(int row : rowsB[j]) {
                            if(picture[row] != picture[i]) {
                                f = false;
                                break;
                            }
                        }
                        
                        if(f) ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};
