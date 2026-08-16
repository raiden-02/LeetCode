//initial solution

class TimeMap {
private:
    map<int, unordered_map<string, string>> ts;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ts[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        for(auto it = ts.rbegin(); it != ts.rend(); it++)
            if(it->first <= timestamp) {
                auto mp = it->second;
                
                if(mp.find(key) != mp.end())
                    return mp[key];
            }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
 
 //optimized binary search(upper bound)
 class TimeMap {
private:
    unordered_map<string, map<int, string>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &x = mp[key];
        auto it = x.upper_bound(timestamp);
        
        return it == x.begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
