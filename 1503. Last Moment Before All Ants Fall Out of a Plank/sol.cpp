class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxl = !left.empty() ? *max_element(left.begin(), left.end()) : numeric_limits<int>::min() / 2;
        int minr = !right.empty() ? *min_element(right.begin(), right.end()) : numeric_limits<int>::max() / 2; 

        return max(0, max(n - minr, maxl));
    }
};
