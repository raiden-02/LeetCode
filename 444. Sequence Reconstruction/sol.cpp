class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> indeg;
        unordered_set<int> nodes;
        
        for(auto &x : seqs) {
            if(x.size() == 1) {
                g[x[0]].push_back(0);
                nodes.insert(x[0]);
                continue;
            }
            nodes.insert(x[0]);
            for(int i = 1; i < x.size(); i++) {
                g[x[i - 1]].push_back(x[i]);
                indeg[x[i]] += 1;
                nodes.insert(x[i]);
            }
        }
        
        int zeroIn = 0;
        queue<int> q;
        for(auto &x : g) {
            if(x.first == 0 || indeg[x.first] != 0) continue;
            q.push(x.first);
            zeroIn += 1;
        }
        
        unordered_set<int> vis;
        vector<int> ord;
        int i = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            ord.push_back(cur);
            vis.insert(cur);
            for(int &neigh : g[cur]) {
                if(neigh == 0 || vis.find(neigh) != vis.end())
                    continue;
                indeg[neigh] -= 1;
                if(indeg[neigh] == 0) {
                    q.push(neigh);
                    vis.insert(neigh);
                    zeroIn += 1;
                }
            }
            if(q.size() > 1)
                return false;
        }
        return ord == org && vis.size() == nodes.size();
    }
};
