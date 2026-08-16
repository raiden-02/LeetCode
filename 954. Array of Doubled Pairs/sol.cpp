class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int x : arr) mp[x]++;
        
        vector<int> keys;
        for(auto &x : mp) keys.push_back(x.first);
        
        sort(keys.begin(), keys.end(), [](int a, int b) {return abs(a) < abs(b);});
        
        for(int x : keys) {
            if(mp[x] > mp[2 * x])
                return false;
            
            mp[2 * x] -= mp[x];
        }
        
        return true;
    }
};
