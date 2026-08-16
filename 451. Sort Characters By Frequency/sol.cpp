class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(char x : s) mp[x]++;
        
        vector<pair<int, char>> sortedMap;
        
        for(auto &x : mp)
            sortedMap.push_back({x.second, x.first});
        
        sort(sortedMap.rbegin(), sortedMap.rend());
        
        string ans;
        
        for(auto &x : sortedMap)
            while(x.first--)
                ans.push_back(x.second);
        
        return ans;
    }
};
