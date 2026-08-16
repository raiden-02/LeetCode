class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() <= 1)
            return 0;
        
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        
        while(pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            
            pq.push(a + b);
            ans += (a + b);
        }
        
        return ans;
    }
};
