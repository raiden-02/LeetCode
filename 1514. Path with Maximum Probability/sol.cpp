class Solution {
public:
    //djikstra algo
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> prob(n);
        prob[start] = 1;
        
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            
            int node = cur.second;
            double curprob = cur.first;
            
            for(auto &[neigh, nprob] : g[node]) {
                if(curprob * nprob > prob[neigh]) //this constraint eliminates the use of set i,e eliminates revisiting unnecessary nodes 
                {
                    prob[neigh] = curprob * nprob;
                    pq.push({prob[neigh], neigh});
                }
            }
        }
        
        return prob[end];
    }
};
