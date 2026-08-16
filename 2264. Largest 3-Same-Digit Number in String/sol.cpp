class Solution {
public:
    string largestGoodInteger(string num) {
        string tmp, ans = "000";
        tmp.push_back(num[0]);
        bool f = false;

        for(int i = 0; i < num.length() - 1; i++) {
            if(num[i] == num[i + 1]) {
                tmp.push_back(num[i]);
            }

            else {
                tmp.clear();
                tmp.push_back(num[i + 1]);
            }

            if(tmp.size() == 3) {
                ans = max(ans, tmp);
                f = true;
            }
        }

        return !f ? ""  : ans;
    }
};
