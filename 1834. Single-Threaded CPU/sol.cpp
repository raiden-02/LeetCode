class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), ind = 0;
        long long freetime = 0;
        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < n; i++)
            tasks[i].push_back(i);
        
        sort(begin(tasks), end(tasks));

        for(int i = 0; i < n or not pq.empty(); ) {
            if(pq.empty() and freetime < tasks[i][0]) {
                freetime = tasks[i][0];
            }

            while(i < n and freetime >= tasks[i][0])
                pq.push({tasks[i][1], tasks[i][2]}), i++;
            
            ans[ind++] = pq.top().second, freetime += pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
