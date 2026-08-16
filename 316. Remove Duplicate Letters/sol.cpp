class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        size_t n = s.length();
        for(char x : s) freq[x]++;
        string ans;
        bitset<26> vis;

        for(size_t i = 0; i < n; i++) {
            freq[s[i]]--;

            if(vis[s[i] - 'a']) continue;

            while(!ans.empty() && s[i] <= ans.back() && freq[ans.back()] > 0) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[ans.back() - 'a'] = true;
        }

        return ans;
    }
};
