class Solution {
public:
    string gcdOfStrings(string const& s, string const& t) {
        return s + t == t + s ? s.substr(0, gcd(s.length(), t.length())) : "";
    }
};
