class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), maxm = 0, minm = numeric_limits<int>::max();
        int s  = 0;
        for(int x : salary) {
            s += x;
            maxm = max(maxm, x);
            minm = min(minm, x);
        }

        return (double)(s - maxm - minm) / (double)(n - 2);
    }
};
