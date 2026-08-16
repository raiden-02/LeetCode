class Solution {
    int helper(vector<int> &arr, int const& n, int ind) {
        if(ind >= n)
            return 1;
        
        int ans = 0;
        
        for(int i = ind; i < n; i++) {
            if(arr[i] % (ind + 1) == 0 or (ind + 1) % arr[i] == 0) {
                swap(arr[ind], arr[i]);
                ans += helper(arr, n, ind + 1);
                swap(arr[ind], arr[i]);
            }
        }
        
        return ans;
    }
public:
    int countArrangement(int n) {
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++)
            arr[i] = i + 1;
        
        return helper(arr, n, 0);
    }
};
