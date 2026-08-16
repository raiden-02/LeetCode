class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        size_t n = arr.size();
        vector<int> ans(n), tarr = arr;
        unordered_map<int, int> mp;

        sort(tarr.begin(), tarr.end());

        for(size_t i = 1, ind = 0; i <= n && ind < n; ind++) {
            if(mp.find(tarr[ind]) == mp.end()) {
                mp[tarr[ind]] = i++;
            } 
        }

        for(size_t i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};
