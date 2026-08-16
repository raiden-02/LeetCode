class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eles = accumulate(nums.begin(), nums.end(), 0);
        int digsum = 0;
        
        for(int x : nums) {
            while(x) {
                int rem = x % 10;
                digsum += rem;
                x /= 10;
            }
        }
        
        return abs(digsum - eles);
    }
};
