class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<set<char>, int> mp;
        int ans = 0;
        
        for(string &x : words) {
            set<char> st(x.begin(), x.end());
            mp[st]++;
        }
        
        for(auto &[k, val] : mp)
            ans += (val * (val - 1)) / 2;
        
        return ans;
    }
};
