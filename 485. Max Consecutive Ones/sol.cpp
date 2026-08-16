class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, ans = 0;
        
        for(int x : nums) {
            if(x) c++;
            else ans = max(ans, c), c = 0;
        }
        
        return max(ans, c);
    }
};
