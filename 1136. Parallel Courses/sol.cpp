class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indeg(N + 1);
        unordered_map<int, vector<int>> g;
        for(auto &x : relations) {
            g[x[0]].push_back(x[1]);
            indeg[x[1]] += 1;
        }
        
        //starting with nodes having 0 indegree
        int zeroin = 0;
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if(indeg[i] == 0) {
                q.push(i);
                zeroin += 1;
            }
        }
        //cout << zeroin << endl;
        
        int ans = 0;
        while(!q.empty()) {
            int s = q.size();
            ans += 1;
            while(s--) {
                int cur = q.front();
                q.pop();
                for(int &neigh : g[cur]) {
                    indeg[neigh] -= 1; //deleting edges from top
                    if(indeg[neigh] == 0) { //if nodes have zero indeg then study course, and increment zeroin
                        q.push(neigh);
                        zeroin += 1;
                    }
                }
            }
        }
        
        //cout << zeroin << endl << endl;
        if(zeroin != N) //if all the courses can't be studied then -1
            return -1;
        return ans;
    }
};
