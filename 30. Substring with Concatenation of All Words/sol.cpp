class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.length(), n = words.size(), wl = words[0].length();
        int slidingWindowSize = n * wl;
        vector<int> ans;
        unordered_map<string, int> wordsFreqMap;

        for(string &word : words) {
            wordsFreqMap[word]++;
        }

        for(int i = 0; i <= m - slidingWindowSize; i++) {
            string tmp;
            unordered_map<string, int> mp;
            bool invalid = false;

            for(int j = i; j < i + slidingWindowSize; j++) {
                if(static_cast<int>(tmp.length()) == wl) {
                    mp[tmp]++;
                    if(mp[tmp] > wordsFreqMap[tmp]) {
                        invalid = true;
                        break;
                    }

                    tmp = "";
                }

                tmp.push_back(s[j]);
            }

            if(invalid) continue;

            mp[tmp]++;

            for(auto &[key, val] : wordsFreqMap) {
                if(val != mp[key]) {
                    invalid = true;
                    break;
                }
            }

            if(!invalid) {
                ans.push_back(i);
            }        
        }

        return ans;
    }
};
