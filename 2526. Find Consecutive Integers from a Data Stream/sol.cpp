class DataStream {
    queue<int> q;
    unordered_map<int, int> mp;
    int val, k;
public:
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        mp[num]++;
        q.push(num);
        
        if((int)q.size() > k) {
            int top = q.front();
            q.pop();
            mp[top]--;
            if(mp[top] == 0) mp.erase(top);
        }
        
        if((int)q.size() == k) {
            return (int)mp.size() == 1 and mp.begin()->first == val;
        }
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
