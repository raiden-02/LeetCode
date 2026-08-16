class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> pos;
        int s = 0;
        
        for(auto &row : wall) {
            int s = 0;
            
            for(int j = 0; j < row.size() - 1; j++)
                s += row[j], pos[s]++;
        }
        
        int mostgaps = 0;
        
        for(auto &[k, v] : pos) 
            mostgaps = max(mostgaps, v);
        
        return wall.size() - mostgaps;
    }
};
