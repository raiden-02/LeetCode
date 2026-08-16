class Solution {
    vector<vector<unordered_map<int, int>>> dp;
    
    int helper(vector<vector<int>> const& arr, int const& tar, int w, int h, int ind) {
        if(ind >= arr.size())
            return h;
        
        if(dp[ind][w].find(h) != dp[ind][w].end())
            return dp[ind][w][h];
        
        int ans = INT_MAX;
        
        if(w + arr[ind][0] <= tar)
            ans = min(ans, helper(arr, tar, w + arr[ind][0], max(h, arr[ind][1]), ind + 1));
        
        ans = min(ans, h + helper(arr, tar, arr[ind][0], arr[ind][1], ind + 1));
        
        return dp[ind][w][h] = ans;
            
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        dp.resize(books.size(), vector<unordered_map<int, int>>(shelf_width + 1));
        return helper(books, shelf_width, 0, 0, 0);
    }
};
