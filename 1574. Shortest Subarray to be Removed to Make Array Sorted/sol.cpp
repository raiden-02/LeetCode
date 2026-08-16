class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0, n = arr.size(), r = n - 1;
        
        while(l + 1 < n and arr[l] <= arr[l + 1])
            l++;
        
        if(l == n - 1)
            return 0;
        
        while(r > l and arr[r - 1] <= arr[r])
            r--;
        
        int ans = min(n - l - 1, r);
        
        int i = 0;
        
        while(i <= l and r < n) {
            if(arr[i] <= arr[r])
                ans = min(ans, r - i - 1), i++;
            else
                r++;
        }
        
        return ans;
    }
};
