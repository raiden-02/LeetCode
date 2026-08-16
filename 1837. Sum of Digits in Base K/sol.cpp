class Solution {
public:
    int sumBase(int n, int k) {
        vector<int> ans;
        
        while(n > 0) {
            int rem = n % k;
            ans.push_back(rem);
            n /= k;
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
