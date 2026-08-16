class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        unordered_map<int, int> freq;
        for(int &x : nums)
            freq[x]++;
        
        int ans = 0;
        unordered_set<int> vis;
        for(int &x : nums) {
            if(vis.find(x) != vis.end()) continue;
            
            int cur = 0;
            if(freq.find(x) != freq.end() && freq.find(x + 1) != freq.end())
                cur = freq[x] + freq[x + 1];
            
            ans = max(ans, cur);
            vis.insert(x);
        }
        return ans;
    }
};
