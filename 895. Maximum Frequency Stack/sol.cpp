class FreqStack {
    priority_queue<vector<int>> pq;
    int rank;
    unordered_map<int, int> mp;
public:
    FreqStack() {
        rank = 0;
    }
    
    void push(int val) {
        pq.push({++mp[val], ++rank, val});
    }
    
    int pop() {
        auto ret = pq.top(); pq.pop();
        int val = ret[2];
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
