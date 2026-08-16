//union find

class Solution {
private:
    unordered_map<int, int> parent;
    int count;
    int find(int i)  {
        if(parent[i] == i) return i;
        
        parent[i] = find(parent[i]);
        return parent[i];
    }
    
    bool merge(int i, int j) {
        int pi = find(i), pj = find(j);
        if(pi == pj)
            return false;
        
        count--;
        parent[pi] = pj;
        return true;
    }
public:
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        if(connections.size() < N - 1)
            return -1;
        
        auto comp = [&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        };
        
        count = N;
        
        sort(connections.begin(), connections.end(), comp);
        
        int cost = 0;
        
        for(int i = 1; i <= N; i++)
            parent[i] = i;
        
        for(auto &x : connections) {
            if(count == 1) return cost;
            
            int cur = x[0], neigh = x[1];
            
            if(merge(cur, neigh))
                cost += x[2];
        }
        return count == 1 ? cost : -1;
    }
};
