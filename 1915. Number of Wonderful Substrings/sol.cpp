class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length(), ans = 0;
        vector<vector<int>> mp(n + 1);
        mp[0].assign(10, 0);
        
        for(int i = 1; i <= n; i++) {
            mp[i] = mp[i - 1];
            mp[i][word[i - 1] - 'a']++;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                int c = 0;
                
                for(int k = 0; k < 10; k++) {
                    if((mp[j][k] - mp[i - 1][k]) % 2) c++;
                    
                    if(c > 1) break;
                }
                
                if(c <= 1) ans++;
            }
        }
        
        return ans;
    }
};

// --- alternate solution ---

//o(N) bitmask
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int mask = 0;
        long long ans = 0;
        unordered_map<int, long long> cnt;
        cnt[0] = 1;
        
        for(char x : word) {
            mask ^= (1 << (x - 'a'));
            ans += cnt[mask];
            
            for(int i = 0; i < 10; i++) {
                int premask = mask ^ (1 << i);
                ans += cnt[premask];
            }
            
            cnt[mask]++;
        }
        
        return ans;
    }
};

//tle
