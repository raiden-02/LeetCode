class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        reverse(s.begin(), s.end());
        int ans = 0;
        int prev = -1;
        
        for(char x : s) {
            int cur = mp[x];
            
            if(cur >= prev)
                ans += cur;
            
            else
                ans -= cur;
            
            prev = cur;
        }
        
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0, prev = -1;
        
        for(int i = s.length() - 1; i >= 0; i--) {
            int cur = mp[s[i]];
            
            if(cur >= prev)
                ans += cur;
            
            else
                ans -= cur;

            prev = cur;
        }
        
        return ans;
    }
};
