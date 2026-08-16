class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n + 1);
        vector<int> oddnodes;
        
        for(auto &x : edges)
            g[x[0]].insert(x[1]), g[x[1]].insert(x[0]);
        
        for(int i = 1; i <= n; i++)
            if(g[i].size() % 2) oddnodes.push_back(i);
        
        int m = oddnodes.size();
        
        if(m == 0)
            return true;
        
        if(m == 2) {
            if(!g[oddnodes[0]].count(oddnodes[1]))
                return true;
            
            int a = oddnodes[0], b = oddnodes[1];
            for(int i = 1; i <= n; i++) {
                if(a != i and b != i and !g[a].count(i) and !g[b].count(i))
                    return true;
            }
        }
        
        if(m == 4) {
            vector<vector<pair<int, int>>> pairs = {{{0, 1}, {2, 3}}, {{0, 2}, {1, 3}}, {{0, 3}, {1, 2}}};
            
            for(auto &x : pairs) {
                auto p1 = x[0], p2 = x[1];
                
                if(!g[oddnodes[p1.first]].count(oddnodes[p1.second]) and !g[oddnodes[p2.first]].count(oddnodes[p2.second]))
                    return true;
            }
        }
        
        return false;           
    }
};
