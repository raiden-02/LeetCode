class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> stats(n);
        for(int i = 0; i < n; i++) stats[i] = {efficiency[i], speed[i]};
        
        sort(stats.rbegin(), stats.rend());
        
        int mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0, ans = 0;
        
        for(auto &x : stats) {
            sum += x.second;
            pq.push(x.second);
            
            while(pq.size() > k)
                sum -= pq.top(), pq.pop();
            
            ans = max(ans, x.first * sum);
        }
        
        return ans % mod;
    }
};
