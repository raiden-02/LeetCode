class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> pc(n);
        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
            pc[i] = {capital[i], profits[i]};

        sort(pc.begin(), pc.end());

        for(int i = 0; k > 0; k--) {
            while(i < n and pc[i].first <= w) {
                pq.push(pc[i++].second);
            }

            if(not pq.empty()) {
                w += pq.top();
                pq.pop();
            }

            else return w;
        }

        return w;
    }
};
