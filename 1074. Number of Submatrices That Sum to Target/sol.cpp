//2d prefix sum similar to subarray sum equals k, time O(mn^2) space O(n)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        
        //prefix sum 2d row wise
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];
        }
        
        //similar to subarray sum equals k problem
        unordered_map<int, int> mp;
        //sliding window
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                int s = 0;
                mp = {{0, 1}};
                
                for(int i = 0; i < m; i++) {
                    s += matrix[i][r] - (l > 0 ? matrix[i][l - 1] : 0);
                    
                    if(mp.find(s - target) != mp.end())
                        ans += mp[s - target];
                    
                    mp[s]++;
                }
            }
        }
        
        return ans;
    }
};
