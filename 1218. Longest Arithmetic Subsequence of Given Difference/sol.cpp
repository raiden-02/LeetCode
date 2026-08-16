class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x] = 1 + mp[x - difference];
            ans = max(mp[x], ans);
        }
        
        return ans;
    }
};
