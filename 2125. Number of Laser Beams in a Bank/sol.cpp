class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastSecurityCount = count(bank[0].begin(), bank[0].end(), '1');
        int ans = 0;

        for(int i = 1; i < bank.size(); i++) {
            int securityCount = count(bank[i].begin(), bank[i].end(), '1');

            if(securityCount > 0 && lastSecurityCount > 0) {
                ans += lastSecurityCount * securityCount;
                lastSecurityCount = securityCount;
            }

            else if(securityCount > 0) {
                securityCount = lastSecurityCount;
            }
        }

        return ans;
    }
};
