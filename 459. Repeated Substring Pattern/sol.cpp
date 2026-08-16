class Solution {
    vector<int> factors(int n) {
        vector<int> ret;

        for(int i = 1; i <= n / 2; i++) {
            if(n % i == 0) ret.push_back(i);
        }

        return ret;
    }
public:
    bool repeatedSubstringPattern(string s) {
        size_t n = s.length();
        vector<int> lengths = factors(n);

        for(int length: lengths) {
            string sub = s.substr(0, length);

            size_t ind = s.find(sub);
            int cnt = 0;

            while(ind != string::npos) {
                cnt++;
                ind = s.find(sub, ind + length);
            }

            if(n / length == cnt) return true;
        }

        return false;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ns = s + s;
        return ns.substr(1, ns.length() - 2).find(s) != string::npos;
    }
};
