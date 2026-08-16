class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), ans1, ans2;
        
        //find if a node has two parents
        for(auto &x : edges) {
            int a = x[0], b = x[1];
            
            if(parent[b] == 0)
                parent[b] = a;
            
            else {
                ans1 = {parent[b], b};
                ans2 = x;
                x[1] = 0;
            }
        }
        
        //same as redundant connections union find
        for(int i = 1; i <= n; i++) parent[i] = i;
        
        for(auto &x : edges) {
            if(x[1] == 0) continue;
            
            int a = x[0], b = x[1];
            
            while(parent[a] != a) a = parent[a];
            while(parent[b] != b) b = parent[b];
            
            if(a == b) {
                if(ans1.empty())
                    return x;
                return ans1;
            }
            
            parent[b] = a;
        }
        
        return ans2;
    }
};
