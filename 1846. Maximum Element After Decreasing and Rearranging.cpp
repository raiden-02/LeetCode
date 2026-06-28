class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 0;
        map<int, int> mp;
        for (int x : arr) mp[x]++;
       
        for (auto &[k, v]: mp) {
            ans = min(k, v + ans);
        }
        return ans;
    }
};
