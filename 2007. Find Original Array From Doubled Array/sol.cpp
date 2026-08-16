class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        if(n % 2) return {};
        
        unordered_map<int, int> mp;
        
        for(int x : changed) mp[x]++;
        
        sort(changed.begin(), changed.end());
        vector<int> ans;
        
        for(int x : changed) {
            if(mp.find(x) == mp.end()) continue;
            if(mp.find(x * 2) == mp.end()) return {};
            
            mp[x]--, mp[x * 2]--;
            if(mp[x] == 0) mp.erase(x);
            if(mp[x * 2] == 0) mp.erase(x * 2);
            
            ans.push_back(x);
        }
        
        return ans;
    }
};
