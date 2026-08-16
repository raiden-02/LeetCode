class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if(arr.size() == 1)
            return 1;
        
        unordered_map<int, int> mp;
        vector<long> dp(arr.size(), 1);
        int mod = 1e9 + 7, ans = 0;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++) {
            int cur = arr[i];
            for(int j = 0; j < i; j++) {
                if(cur % arr[j] == 0) {
                    int div = cur / arr[j];
                    if(mp.find(div) != mp.end())
                        dp[i] += dp[mp[arr[j]]] * dp[mp[div]];
                }
            }
            dp[i] %= mod;
            mp[cur] = i;
            ans = (ans + dp[i]) % mod;
        }
        
        return ans;
    }
};
