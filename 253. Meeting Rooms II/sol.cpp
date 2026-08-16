class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int ans = 0;
        for(auto &x : intervals) {
            if(pq.empty()) {
                //pq.push(x[1]);
                ans += 1;
            }
            else {
                if(pq.top() > x[0])
                    ans += 1;
                else
                    pq.pop();
            }
            pq.push(x[1]);
            //cout << ans << " " << pq.top() << endl;
        }
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &x : intervals) {
            if(not pq.empty() and pq.top() <= x[0])
                pq.pop();
            
            pq.push(x[1]);
        }

        return pq.size();
    }
};
