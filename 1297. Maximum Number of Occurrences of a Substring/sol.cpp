//main greedy catch, max occurences of substring implies counting substrings with criteria length == minSize and unique characters <= maxLetters is enough

//set solution kinda intuitive
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int r = 0, l = 0, n = s.length(), ans = 0;
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++) {
            if(minSize > n - i) break;
            
            string cur = s.substr(i, minSize);
            //cout << cur << endl;
            unordered_set<char> st(cur.begin(), cur.end());

            if(st.size() <= maxLetters) {
                mp[cur]++;
                //cout << mp[cur] << " ";
                ans = max(ans, mp[cur]);
                //cout << ans << endl;
            }
        }
        
        return ans;
    }
};

//sliding window

// --- alternate solution ---

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int r = 0, l = 0, n = s.length(), ans = 0;
        unordered_map<string, int> mp;
        unordered_map<char, int> freq;
        while(r < n)  {
            freq[s[r]]++;
            
            if(r - l + 1 > minSize) {
                freq[s[l]]--;
                
                if(freq[s[l]] == 0)
                    freq.erase(s[l]);
                
                l++;
            }
            
            if(r - l + 1 == minSize && freq.size() <= maxLetters)
                ans = max(ans, ++mp[s.substr(l, r - l + 1)]);
            
            r++;
        }
        
        return ans;
    }
};
