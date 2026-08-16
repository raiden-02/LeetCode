class Solution {
    unordered_map<int, int> mp;
    vector<unordered_map<int, bool>> dp;
    
    bool helper(vector<int> const& arr, int ind, int jump) {
        if(ind >= arr.size() - 1)
            return true;
        
        if(dp[ind].find(jump) != dp[ind].end())
            return dp[ind][jump];
        
        int cur = arr[ind];
        vector<int> nextj = {jump - 1, jump, jump + 1};
        
        for(int &nj : nextj) {
            int stone = cur + nj;
            
            if(stone != cur && mp.find(stone) != mp.end() && helper(arr, mp[stone], nj)) {
                return dp[ind][jump] = true;
            }
        }
        
        return dp[ind][jump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        for(int i = 0; i < n; i++)
            mp[stones[i]] = i;
        
        dp.resize(n);
        
        return helper(stones, 0, 0);
    }
};
