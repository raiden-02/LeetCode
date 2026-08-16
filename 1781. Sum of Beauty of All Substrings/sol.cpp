class Solution {
public:
    int beautySum(string s) {
        unordered_map<char, int> mp;
        int n = s.length(), ans = 0;
        
        for(int i = 0; i < n - 1; i++) {
            mp.clear();
            
            for(int j = i; j < n; j++) {
                mp[s[j]]++;
                
                int mx = 0, mn = n;
                
                for(auto &x : mp)
                    mx = max(mx, x.second), mn = min(mn, x.second);
                
                ans += (mx - mn);
            }
        }
        
        return ans;
    }
};
