class Solution {
    class UnionFind {
    private:
        int n;
        vector<int> parent;
        vector<int> rank;
    public:
        int weight = 0;
        int edges = 0;

        UnionFind(int n) {
            this->n = n;
            parent.resize(n);
            for(int i = 0; i < n; i++) parent[i] = i;
            rank.resize(n);
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void merge(int x, int y, int w) {
            int px = find(x), py = find(y);

            if(px == py) return;

            if(rank[px] > rank[py]) {
                parent[py] = px;
            }

            else if(rank[py] > rank[px]) {
                parent[px] = py;
            }

            else {
                parent[px] = py;
                rank[py]++;
            }

            weight += w; edges++;
        }
    };
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(size_t i = 0; i < edges.size(); i++) edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        // find MST weight first
        size_t m = edges.size();
        unique_ptr<UnionFind> mst1 = make_unique<UnionFind>(n);

        for(auto &x : edges) {
            mst1->merge(x[0], x[1], x[2]);
        }

        vector<int> criticalEdges, pseudoCriticalEdges;
        int minWeight = mst1->weight;

        // Remove each edge and find MST to check if its critical or pseudocritical
        for(int i = 0; i < m; i++) {
            auto mst2 = make_unique<UnionFind>(n);

            for(int j = 0; j < m; j++) {
                if(i == j) continue;

                mst2->merge(edges[j][0], edges[j][1], edges[j][2]);
            }

            if(mst2->weight > minWeight || mst2->edges < n - 1)
                criticalEdges.push_back(edges[i][3]);
            
            // pseudocritical => if force including that edge (by merge it first) gives an MST 
            else {
                auto mst3 = make_unique<UnionFind>(n);
                mst3->merge(edges[i][0], edges[i][1], edges[i][2]);

                for(int j = 0; j < m; j++)
                    mst3->merge(edges[j][0], edges[j][1], edges[j][2]);
                
                if(mst3->weight == minWeight)
                    pseudoCriticalEdges.push_back(edges[i][3]);
            }
        }

        return {criticalEdges, pseudoCriticalEdges};
    }
};
