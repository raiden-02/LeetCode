class Solution {
    unordered_map<string, vector<string>> g;
    vector<vector<string>> ans;
    unordered_map<string, bool> vis;
public:
    vector<string> bfs(string &start) {
        if(vis[start]) return {};
        vector<string> ret;
        queue<string> q;
        q.push(start);
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            vis[cur] = true;
            ret.push_back(cur);
            for(string &x : g[cur]) {
                if(vis[x]) continue;
                q.push(x);
                vis[x] = true;
            }
        }
        return ret;
    }
    /*
    bool Same(string &s) {
        for(auto &x : ans) {
            if(find(x.begin(), x.end(), s) != x.end())
                return true;
        }
        return false;
    }*/
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &x : accounts) {
            for(int i = 1; i < x.size(); i++) {
                for(int j = 1; j < x.size(); j++) {
                    if(i == j) continue;
                    g[x[i]].push_back(x[j]);
                    g[x[j]].push_back(x[i]);
                }
            }
        }
        
        for(auto &x : accounts) {
            //if(!Same(x[1])) continue;
            vector<string> tmp = bfs(x[1]);
            if(!tmp.empty()) {
                sort(tmp.begin(), tmp.end());
                tmp.insert(tmp.begin(), x[0]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
