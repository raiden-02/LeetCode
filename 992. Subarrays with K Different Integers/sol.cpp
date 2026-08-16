class Solution {
    int atMostK(vector<int> const& nums, int k) {
        unordered_map<int, int> vis;
        int l = 0, n = nums.size(), ans = 0, prevl = -1;

        for(int r = 0; r < n; r++) {
            vis[nums[r]]++;
            
            while((int)vis.size() > k) {
                vis[nums[l]]--;
                if(vis[nums[l]] == 0) vis.erase(nums[l]);
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1); //exactly k = atmost k - atmost k - 1
    }
};
