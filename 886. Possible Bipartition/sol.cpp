class Solution {
    bool dfs(vector<vector<int>> const& g, int player, vector<int> &captain, int cap) {
        captain[player] = cap;
        
        for(auto &x : g[player]) {
            if(captain[x] == -1) {
                if(not dfs(g, x, captain, (cap + 1) % 2))
                    return false;
            }
            
            else if(captain[x] == captain[player])
                return false;
        }
        
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n + 1);
        vector<int> captain(n + 1, -1);
        
        for(auto &x : dislikes)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        bool ans = true;
        
        for(int i = 1; i <= n; i++)
            if(captain[i] == -1)
                ans = ans and dfs(g, i, captain, 0);
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
    unordered_map<int, vector<int>> g;
    vector<int> groups;

    bool dfs(int cur, int group) {
        groups[cur] = group;

        for(int neigh : g[cur]) {
            if(groups[neigh] == -1) {
                if(not dfs(neigh, (group + 1) % 2))
                    return false;
            }
            
            else if(groups[cur] == groups[neigh])
                return false;
        }
        
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        groups.resize(n + 1, -1);

        bool ans = true;

        for(auto &x : dislikes)
            g[x[0]].push_back(x[1]), g[x[1]].push_back(x[0]);
        
        for(int i = 1; i <= n; i++) {
            if(groups[i] == -1)
                ans &= dfs(i, 0);
        }

        return ans;
    }
};
