class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return 0;
        
        vector<int> dp(n);
        int diff = nums[1] - nums[0], ans = 0;
        
        for(int i = 2; i < n; i++) {
            int curd = nums[i] - nums[i - 1];
            
            if(curd == diff) 
                dp[i] = dp[i - 1] + 1;
            else
                diff = curd;
            
            ans += dp[i];
        }
        
        return ans;
    }
};

//c++

// --- alternate solution ---

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;

        int d = A[1] - A[0], ans = 0, t = 1;
        for(int i = 2; i < A.size(); i++) {
            int cur = A[i] - A[i - 1];
            if(cur == d) {
                ans += t;
                t += 1;
            }
            else {
                t = 1;
                d = cur;
            }
        }
        return ans;
    }
};

#python
