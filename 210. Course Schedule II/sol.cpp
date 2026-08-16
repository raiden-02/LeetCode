class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        unordered_map<int, vector<int>> g;
        for(auto &x : prerequisites) {
            g[x[1]].push_back(x[0]);
            indeg[x[0]] += 1;
        }
        
        int zeroIn = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
                zeroIn += 1;
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int &neigh : g[cur]) {
                indeg[neigh] -= 1;
                if(indeg[neigh] == 0) {
                    q.push(neigh);
                    zeroIn += 1;
                }
            }
        }
        if(zeroIn != numCourses) return {};
        return ans;
    }
};
