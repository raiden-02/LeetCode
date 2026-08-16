class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort
        vector<int> indeg(numCourses);
        unordered_map<int, vector<int>> g;
        for(auto &x : prerequisites) {
            g[x[1]].push_back(x[0]); //start from course[1] to course[0] in that order while taking them
            indeg[x[0]] += 1; //course[0] now has one prereq, i,e, indeg[course[0]] += 1
        }
        
        //put all the nodes which have no prerequisites in queue, i,e indeg
        queue<int> q;
        int zeroIn = 0;
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
                zeroIn += 1;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int &neigh : g[cur]) {
                indeg[neigh] -= 1; //removing each prereq for that course i,e completing the prereqs prior
                if(indeg[neigh] == 0) { //completed courses push in queue
                    q.push(neigh);
                    zeroIn += 1;
                }
            }
        }
        
        return zeroIn == numCourses;
    }
};
