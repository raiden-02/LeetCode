class Solution {
    unordered_map<string, vector<pair<string, bool>>> g;
    vector<string> ans;
public:
    void dfs(pair<string, bool> &cur) {
        if(cur.second)
            return;
        cur.second = true;
        
        for(auto &neigh : g[cur.first])
            dfs(neigh);
        ans.push_back(cur.first);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x : tickets)
            g[x[0]].push_back({x[1], false});
        for(auto &x : g)
            sort(x.second.begin(), x.second.end());
        pair<string, bool> start = make_pair("JFK", false);
        dfs(start);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
