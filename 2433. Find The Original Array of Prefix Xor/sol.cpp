class Solution {
    /*101 - now
    010 - want
    111 - new

    010 - now
    000 - want
    010 - new

    000 - now
    011 - want
    011 - new

    011 - now
    001 - want
    010 - new*/


public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0] = pref[0];

        for(size_t i = 1; i < pref.size(); i++) {
            ans[i] = pref[i - 1] ^ pref[i];
        }

        return ans;
    }
};
