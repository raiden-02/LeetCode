class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(begin(piles), end(piles));
        int ans = 0;

        while(k-- and not pq.empty()) {
            int cur = pq.top(); pq.pop();
            cur -= floor(cur / 2);
            pq.push(cur);
        }

        while(not pq.empty())
            ans += pq.top(), pq.pop();
        
        return ans;
    }
};
