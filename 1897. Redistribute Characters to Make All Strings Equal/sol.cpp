class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;
        int n = words.size();
        
        for(string &x : words) {
            for(char y : x)
                mp[y]++;
        }
        
        for(auto &x : mp) {
            if(x.second % n)
                return false;
        }
        
        return true;
    }
};
