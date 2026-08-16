class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        
        int l = 0, r = 0, ans = 0;
        unordered_set<char> st;
        
        while(r < s.length()) {
            if(st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                ans = max(ans, (int)st.size());
                r += 1;
            }
            
            else {
                st.erase(s[l]);
                l += 1;
            }
        }
        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, n = s.length(), ans = 0;

        for(int r = 0; r <  n; r++) {
            mp[s[r]]++;

            while(l < r and mp[s[r]] > 1) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            // cout << r << " " << l << endl;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// --- alternate solution ---

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.length(), ans = 0;
        
        while(r < n) {
            mp[s[r]]++;
            
            while(mp[s[r]] > 1 and l <= r)
                mp[s[l]]--, l++;
            
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};
