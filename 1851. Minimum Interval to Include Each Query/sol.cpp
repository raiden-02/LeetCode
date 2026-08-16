class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size(), m = intervals.size();
        vector<pair<int, int>> arr(n);
        
        for(int i = 0; i < n; i++)
            arr[i] = {queries[i], i};
        
        sort(intervals.begin(), intervals.end()), sort(arr.begin(), arr.end());
        
        int j = 0;
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto &x : arr) {
            int &cur = x.first;
            
            for(; j < m and intervals[j][0] <= cur; j++) {
                if(cur <= intervals[j][1])
                    pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
            }
            
            while(not pq.empty() and pq.top().second < cur)
                pq.pop();
            
            ans[x.second] = not pq.empty() ? pq.top().first : -1; 
        }
        
        return ans;
    }
};
