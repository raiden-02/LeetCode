class LRUCache {
    list<pair<int, int>> dl; //list to hold key value pairs, recent one at the beginning
    unordered_map<int, list<pair<int, int>>::iterator> mp; //map to hold key and its respective iterator inside the list to delete whenever necessary
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        int ret = -1;
        
        if(it != mp.end()) {
            auto del = it->second;
            ret = del->second;
            dl.erase(del);
            
            dl.push_front({key, ret});
            mp[key] = dl.begin();
        }
        
        return ret;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        
        if(it != mp.end())
            dl.erase(it->second);
        
        else if(cap == 0) {
            int del = dl.back().first;
            mp.erase(del);
            dl.pop_back();
        }
        
        else cap--;
        
        dl.push_front({key, value});
        mp[key] = dl.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
