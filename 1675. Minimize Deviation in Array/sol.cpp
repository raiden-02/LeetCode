class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minm = numeric_limits<int>::max(), ans = minm;
        
        for(int x : nums) {
            if(x % 2) x *= 2;
            pq.push(x);
            minm = min(minm, x);
        }

        while(not pq.empty()) {
            int maxm = pq.top(); pq.pop();
            ans = min(ans, maxm - minm);
            
            if(maxm % 2) return ans;
            
            maxm /= 2;
            minm = min(minm, maxm);
            pq.push(maxm);
        }

        return ans;
    }
};
