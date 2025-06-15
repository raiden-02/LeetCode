class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // 1) Build 'a' by replacing the first non-'9' digit with '9'
        char toReplaceA = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceA = c;
                break;
            }
        }
        if (toReplaceA) {
            for (char &c : a)
                if (c == toReplaceA)
                    c = '9';
        }

        // 2) Build 'b' by a two-step rule:
        //    - If the first digit != '1', replace all of that digit with '1'.
        //    - Otherwise, find the first digit (after the leading one)
        //      that is not '0' or '1', and replace all of it with '0'.
        if (s[0] != '1') {
            char toReplaceB = s[0];
            for (char &c : b)
                if (c == toReplaceB)
                    c = '1';
        } else {
            char toReplaceB = 0;
            for (int i = 1; i < (int)s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceB = s[i];
                    break;
                }
            }
            if (toReplaceB) {
                for (char &c : b)
                    if (c == toReplaceB)
                        c = '0';
            }
        }

        return stoi(a) - stoi(b);
    }
};
