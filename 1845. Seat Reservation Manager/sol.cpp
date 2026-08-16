class SeatManager {
    vector<bool> avail;
    
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        avail.resize(n, true);
        
        for(int i = 0; i < n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int cur = pq.top();
        
        if(avail[cur]) {
            avail[cur] = false;
            pq.pop();
            return cur + 1;
        }
        
        pq.pop();
        return reserve();
    }
    
    void unreserve(int seatNumber) {
        avail[seatNumber - 1] = true;
        pq.push(seatNumber - 1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
