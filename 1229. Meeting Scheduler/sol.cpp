class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq1(slots1.begin(),slots1.end()), pq2(slots2.begin(), slots2.end());
        
        while(!pq1.empty() and !pq2.empty()) {
            auto a = pq1.top();
            auto b = pq2.top();
            
            int ms = max(a[0], b[0]);
            int me = min(a[1], b[1]);
            
            if(me - ms >= duration)
                return {ms, ms + duration};
            
            if(a[1] == b[1])
                pq1.pop(), pq2.pop();
            
            else if(a[1] > b[1])
                pq2.pop();
            else
                pq1.pop();
        }
        
        return {};
    }
};
