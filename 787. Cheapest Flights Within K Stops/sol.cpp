class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dists(n,  numeric_limits<int>::max());
        vector<vector<pair<int, int>>> g(n);

        for(auto &x : flights) {
            g[x[0]].push_back({x[1], x[2]});
        }

        dists[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        k++;

        while(k-- && !q.empty()) {
            int s = q.size();

            while(s--) {
                auto cur = q.front(); q.pop();
                int curn = cur.first, curd = cur.second;

                for(auto &neigh : g[curn]) {
                    int nn = neigh.first, nd = neigh.second;

                    if(curd + nd < dists[nn]) {
                        dists[nn] = curd + nd;
                        q.push({nn, dists[nn]});
                    }
                }
            }
        }

        return dists[dst] == numeric_limits<int>::max() ? -1 : dists[dst];
    }
};
