class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0, r = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        for(; l < candidates; l++) pq1.push(costs[l]); 
        for(; r >= max(candidates, (int)costs.size() - candidates); r-- && costs[r]) pq2.push(costs[r]);
        long long ans = 0;

        while(k--) {
            if(pq2.empty() || !pq1.empty() && pq1.top() <= pq2.top()) {
                ans += pq1.top();
                pq1.pop();
                if(l <= r) pq1.push(costs[l++]);
            }


            else {
                ans += pq2.top();
                pq2.pop();
                if(r >= l) pq2.push(costs[r--]);
            }
        }

        return ans;
        
    }
};
