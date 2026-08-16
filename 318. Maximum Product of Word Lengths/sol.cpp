//intuitive bitset
class Solution {
    bool helper(bitset<26> const& a, bitset<26> const& b) {
        for(int i = 0; i < 26; i++)
            if(a[i] and b[i]) return false;
        return true;
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> mp(n);
        
        for(int i = 0; i < n; i++) {
            for(char &x : words[i])
                mp[i][x - 'a'] = 1;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(i != j and helper(mp[i], mp[j]))
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        
        return ans;
    }
};

//intuitive O(n**2 * m**2)

// --- alternate solution ---

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        
        for(int i = 0; i < words.size() - 1; i++) {
            for(int j = i + 1; j < words.size(); j++) {
                bool f = false;
                
                for(char x : words[i]) {
                    if(words[j].find(x) != string::npos) {
                        f = true;
                        break;
                    }
                }
                
                if(not f)
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        
        return ans;
    }
};

//bitmask O(n**2 + len of two strings)

// --- alternate solution ---

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        vector<int> bitmask(n);
        
        for(int i = 0; i < n; i++) {
            
            for(char x : words[i])
                bitmask[i] |= (1 << (x - 'a'));
            
            for(int j = 0; j < i; j++) {
                if(not (bitmask[i] & bitmask[j]))
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        
        return ans;
    }
};
