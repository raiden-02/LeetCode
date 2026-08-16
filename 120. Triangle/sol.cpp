class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        if(n == 1)
            return triangle[0][0];
        
        int ans = 1e4 + 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                int b = j - 1 < triangle[i - 1].size() ? triangle[i - 1][j - 1] : (1e4 + 1);
                int a = j < triangle[i - 1].size() ? triangle[i - 1][j] : (1e4 + 1);
                
                triangle[i][j] += min(a, b);
                
                if(i == n - 1)
                    ans = min(ans, triangle[i][j]);
            }
        }
        
        return ans;
    }
};
