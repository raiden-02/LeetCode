class Solution {
    vector<bool> vis;
    int ans = 0;
    
    void dfs(vector<vector<int>> const& stones, int ind) {
        for(int i = 0; i < stones.size(); i++) {
            if(vis[i]) continue;
            
            if(stones[i][0] == stones[ind][0] or stones[i][1] == stones[ind][1])
                vis[i] = true, dfs(stones, i);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vis.resize(stones.size(), false);
        
        for(int i = 0; i < stones.size(); i++) {
            if(vis[i]) continue;
            ans++, vis[i] = true, dfs(stones, i);
        }
        
        return stones.size() - ans;
    }
};
