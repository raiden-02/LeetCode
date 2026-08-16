class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        bitset<8> cur, next;
        unordered_map<string, int> mp;
        
        for(int i = 0; i < 8; i++) cur[i] = cells[i];
        
        while(n) {
            mp[cur.to_string()] = n--;
            
            for(int i = 1; i < 7; i++)
                next[i] = cur[i - 1] == cur[i + 1] ? 1 : 0;
            
            cur = next;
            string key = cur.to_string();
            
            if(mp.find(key) != mp.end())
                n %= mp[key] - n;
        }
        
        vector<int> ans(8);
        for(int i = 0; i < 8; i++) ans[i] = cur[i];
        
        return ans;
    }
};
