class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0;

        for(int i = num.size() - 1; i >= 0 or k or carry;) {
            int a = k > 0 ? k % 10 : 0;
            int b = i >= 0 ? num[i--] : 0;

            int s = a + b + carry;
            ans.push_back(s % 10);
            carry = s / 10;
            if(k > 0) k /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
