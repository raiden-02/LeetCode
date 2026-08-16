class MyHashMap {
    vector<int> arr;
public:
    MyHashMap() {
        arr.resize(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
 class MyHashMap {
    vector<pair<int, int>> mp;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mp = vector<pair<int, int>>();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for(auto &x : mp) {
            if(x.first == key) {
                x.second = value;
                return;
            }
        }
        mp.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(auto &x : mp) {
            if(x.first == key)
                return x.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->first == key) {
                mp.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
