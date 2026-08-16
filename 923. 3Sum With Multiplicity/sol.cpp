class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int mod = 1e9 + 7, ans = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(target - arr[i]) != mp.end())
                ans = (ans + mp[target - arr[i]]) % mod;
            
            for(int j = 0; j < i; j++)
                mp[arr[i] + arr[j]]++;
        }
        
        return ans % mod;
    }
};
