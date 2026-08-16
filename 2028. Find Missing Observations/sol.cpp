class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sm = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int x = mean * (m + n) - sm;

        int elem = x / n;
        if(elem <= 0 || elem > 6) return {};
        int rem = x % n;

        vector<int> ans(n, elem);
        for(int i = 0; i < n && rem > 0; i++)
            if(ans[i] < 6) ans[i]++, rem--;

        return rem == 0 ? ans : vector<int>();
    }
};
