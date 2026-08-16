class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1) return 0;
        
        int ans = 0;

        while(n > 2) {
            int mat = n / 2;
            int teams = n - n / 2;
            ans += mat;
            n = teams;
        }

        return ans + 1;
    }
};
