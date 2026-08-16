class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = INT_MIN, ans2 = INT_MAX, s1 = 0, s2 = 0;
        
        for(int &x : nums) {
            s1 += x;
            s2 += x;
            s1 = max(s1, x);
            s2 = min(s2, x);
            ans1 = max(s1, ans1);
            ans2 = min(s2, ans2);
        }
        
        return max(abs(ans1), abs(ans2));
    }
};
