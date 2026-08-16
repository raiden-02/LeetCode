//intuitve merge intervals O(nlogn) solution
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(intervals.begin(), intervals.end());
        
        while(pq.size() > 1) {
            auto cur = pq.top(); pq.pop();
            auto next = pq.top(); pq.pop();
            
            if(next[0] > cur[1]) {
                ans.push_back(cur);
                pq.push(next);
            }
            
            else if(next[0] <= cur[1])
                pq.push({cur[0], max(next[1], cur[1])});
        }
        
        if(not pq.empty())
            ans.push_back(pq.top());
        
        return ans;
    }
};

//O(n)

// --- alternate solution ---

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while(i < n and intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        
        while(i < n and intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);
        
        while(i < n)
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};
