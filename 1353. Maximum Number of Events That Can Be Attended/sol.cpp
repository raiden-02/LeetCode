class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, i = 0;
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int day = 1; day <= 100000; day++) {
            while(not pq.empty() and pq.top() < day)
                pq.pop();
            
            while(i < events.size() and events[i][0] == day)
                pq.push(events[i++][1]);
            
            if(not pq.empty()) ans++, pq.pop();
        }
        
        return ans;
    }
};

import java.util.*;
