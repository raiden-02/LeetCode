class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char, int> mp = {{'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5}};
        
        int r = 0, l = 0, ans = 0;
        char prev = 'a' - 1;
        unordered_set<char> st;
        
        while(r < word.length()) {
            //cout << l << " " << r << endl;
            //cout << mp[word[r]] - mp[prev] << endl;
            int d = mp[word[r]] - mp[prev];
            if(d <= 1 and d >= 0) {
                st.insert(word[r]); {
                if(st.size() == 5)
                    ans = max(ans, r - l + 1);
                }
            }
            
            else {
                while(l != r)
                    l++;
                st.clear();
                st.insert(word[l]);
            }
            
            prev = word[r];
            r++;
        }
        
        return ans;
    }
};
