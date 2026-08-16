class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0, curp = startFuel, i = 0;
        priority_queue<int> pq;
        
        while(curp < target) {
            while(i < stations.size() and stations[i][0] <= curp)
                pq.push(stations[i++][1]);
            
            if(pq.empty()) return -1;
            curp += pq.top(), pq.pop();
            ans++;
        }
        
        return ans;
    }
};
