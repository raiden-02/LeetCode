class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char x : s) mp[x]++;

        bool f = false;
        int ans = 0;

        for(auto &x : mp) {
            if(x.second % 2) {
                if(!f) {
                    ans += x.second;
                    f = true;
                }

                else ans += x.second - 1;
            }

            else {
                ans += x.second;
            }
        }

        return ans;
    }
};
