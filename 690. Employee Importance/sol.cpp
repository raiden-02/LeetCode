class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> imp;
        int start;
        queue<int> q;

        for(Employee* emp : employees) {
            g[emp->id] = emp->subordinates;
            imp[emp->id] = emp->importance;
            if(emp->id == id)
                start = id;
        }

        q.push(start);
        int ans = imp[start];
        unordered_set<int> vis;
        vis.insert(start);

        while(not q.empty()) {
            int cur = q.front(); q.pop();

            for(int sub : g[cur]) {
                if(vis.count(sub)) continue;

                vis.insert(sub);
                q.push(sub);
                ans += imp[sub];        
            }
        }

        return ans;
    }
};

// --- alternate solution ---

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
