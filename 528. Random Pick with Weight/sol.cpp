class Solution {
    vector<int> accum;
public:
    Solution(vector<int>& w) {
        int s = 0;
        
        for(int &x : w) {
            s += x;
            accum.push_back(s);
        }
    }
    
    int pickIndex() {
        int randnum = rand() % accum.back();
        return upper_bound(accum.begin(), accum.end(), randnum) - accum.begin();
        // returning index of the upper bound (first >) random number in the range w[0] to sum(w), weight distribution is done by prefix sum
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
