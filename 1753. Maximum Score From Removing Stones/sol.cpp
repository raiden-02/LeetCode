class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);
        int ans = 0;
        
        while(pq.size() >= 2) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            x--, y--, ans++;
            
            if(x)
                pq.push(x);
            if(y)
                pq.push(y);
        }
        
        return ans;
    }
};
