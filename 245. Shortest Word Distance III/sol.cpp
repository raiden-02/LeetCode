class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, int> mp;
        int ans = wordsDict.size();
        
        for(int i = 0; i < wordsDict.size(); i++) {
            if(wordsDict[i] == word2 and mp.find(word1) != mp.end())
                ans = min(ans, i - mp[word1]);
            
            if(wordsDict[i] == word1 and mp.find(word2) != mp.end())
                ans = min(ans, i - mp[word2]);
            
            mp[wordsDict[i]] = i;
        }
        
        return ans;
    }
};
