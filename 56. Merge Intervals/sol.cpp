class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        while(pq.size() > 1) {
            auto cur = pq.top(); pq.pop();
            auto next = pq.top(); pq.pop();
            int minm = cur[0], maxm = max(cur[1], next[1]);
            
            if(cur[1] >= next[0])
                pq.push({minm, maxm});
            
            else
                ans.push_back({cur[0], cur[1]}), pq.push(next);
        }
        
        if(not pq.empty()) ans.push_back(pq.top());
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            
            else
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};
