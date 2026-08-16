class Solution {
    unordered_map<string, int> mp;
    
    string key(vector<int> &arr) {
        string k;
        for(int &x : arr)
            k += to_string(x);
        return k;
    }
    
    bool check(vector<int> &a, vector<int> &b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] < b[i])
                return false;
        }
        return true;
    }
    
    int helper(vector<int> &price, vector<vector<int>> &sp, vector<int> need) {
        string k = key(need);
        
        if(mp.find(k) != mp.end())
            return mp[k];
        
        int ans = INT_MAX;
        for(auto &offer : sp) {
            if(check(need, offer)) {
                vector<int> temp(need.size());
                for(int i = 0; i < need.size(); i++)
                    temp[i] = need[i] - offer[i];
                ans = min(ans, offer.back() + helper(price, sp, temp));
            }
        }
        
        int s = 0;
        for(int i = 0; i < need.size(); i++)
            s += need[i] * price[i];
        ans = min(ans, s);
        return mp[k] = ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, needs);
    }
};
