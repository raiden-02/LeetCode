class Solution {
    vector<bool> vis;
    bool helper(vector<int> const& arr, int start) {
        if(start < 0 || start >= arr.size())
            return false;
        
        if(arr[start] == 0)
            return true;
        
        if(vis[start])
            return false;
        vis[start] = true;
        
        return helper(arr, start + arr[start]) || helper(arr, start - arr[start]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vis = vector<bool>(arr.size());
        return helper(arr, start);
    }
};
