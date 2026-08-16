class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = index, r = l, ans = 1, s = n;
        
        while(s + (r - l + 1) <= maxSum) {
            s += (r - l + 1);
            
            l = l - 1 >= 0 ? l - 1 : l;
            r = r + 1 < n ? r + 1 : r;
            ans++;
            
            if(l == 0 and r == n - 1) {
                int diff = maxSum - s;
                s += diff;
                ans += (diff / n);
            }
        }
        
        return ans;
    }
};
