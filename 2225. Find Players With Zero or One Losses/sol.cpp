class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        unordered_set<int> vis;
        
        for(auto &x : matches)
            losses[x[1]]++, vis.insert(x[0]), vis.insert(x[1]);
        
        vector<vector<int>> ans(2);
        
        for(int x : vis) {
            if(losses.find(x) == losses.end())
                ans[0].push_back(x);
            
            else if(losses[x] == 1)
                ans[1].push_back(x);
        } 
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};
