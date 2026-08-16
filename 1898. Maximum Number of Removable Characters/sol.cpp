class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.length(), m = p.length(), o = removable.size();
        
        vector<int> mp(n, INT_MAX);
        for(int i = 0; i < o; i++)
            mp[removable[i]] = i;
        
        int l = 0, r = o;
        
        while(l < r) {
            int mid = (l + r + 1) >> 1, j = 0;
            
            for(int i = 0; i < n and j < m; i++) {
                if(mp[i] >= mid and s[i] == p[j])
                    j++;
            }
            
            if(j == m)
                l = mid;
            
            else
                r = mid - 1;
        }
        
        return l;
    }
};
