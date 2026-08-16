class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j])
                    dp[i] = max(1 + dp[j], dp[i]);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

// --- alternate solution ---

//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        
        for(int &x : nums) {
            auto it = lower_bound(ans.begin(), ans.end(), x);
            
            if(it == ans.end()) ans.push_back(x);
            else *it = x; //*it = value at it, change it to x
        }
        
        return ans.size();
    }
};


//O(n**2) intuitive
