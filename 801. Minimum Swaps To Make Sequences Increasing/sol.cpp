class Solution {
    vector<vector<int>> dp;
    int helper(vector<int> &A, vector<int> &B, int a, int b, int ind, int s) {
        if(ind == A.size())
            return 0;
        
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int ans = INT_MAX;
        if(A[ind] > a && B[ind] > b)
            ans = helper(A, B, A[ind], B[ind], ind + 1, 0); //0 = dont swap
        
        if(A[ind] > b && B[ind] > a)
            ans = min(ans, helper(A, B, B[ind], A[ind], ind + 1, 1) + 1); //1 = swap
        
        return dp[ind][s] = ans;
    }
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        dp = vector<vector<int>>(A.size() + 1, vector<int>(2, -1));
        return helper(A, B, -1, -1, 0, 0);
    }
};
