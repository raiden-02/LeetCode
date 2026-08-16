class Solution {
private:
    unordered_map<int, int> parent;
    
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int count = 0;
    
    //find the parent of i
    int find(int i) {
        if(parent[i] == i)
            return i;
        parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    //union is a keyword for c++ so merge instead
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        
        if(pi == pj)
            return; //if both have the same parent
        
        count--; //decrement overall no of islands
        parent[pi] = pj; //make them have same parent i,e merge them
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        
        auto bound = [&](int &x, int &y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        
        for(auto &pos : positions) {
            int x = pos[0], y = pos[1];
            int key = x * n + y; //unique key value for a position
            
            //overriden find with union find's find
            if(parent.find(key) != parent.end()) { //if the cur pos is already a parent itself
                ans.push_back(count);
                continue;
            }
            
            count++; //otherwise increment count of islands and make the cur pos as key
            parent[key] = key;
            
            for(auto &dir : dirs) {
                int dx = x + dir.first, dy = y + dir.second;
                
                if(bound(dx, dy)) {
                    int dkey = dx * n + dy;
                    
                    if(parent.find(dkey) != parent.end()) //if neighbour is already a parent
                        merge(key, dkey);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
