class Logger {
    unordered_map<string, int> mp;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        bool ans = true;
        if(mp.count(message)) {
            ans = mp[message] <= (timestamp - 10);
        }
        if(ans) mp[message] = timestamp;
        return ans;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
