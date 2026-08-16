class HitCounter {
    long times[300], hits[300];
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int ind = timestamp % 300;
        
        if(timestamp != times[ind]) {
            times[ind] = timestamp, hits[ind] = 1;
            return;
        }
        
        hits[ind]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int ans = 0;
        
        for(int i = 0; i < 300; i++) {
            if(timestamp - times[i] < 300)
                ans += hits[i];
        }
        
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
