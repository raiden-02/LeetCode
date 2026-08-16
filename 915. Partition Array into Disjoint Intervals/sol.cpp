class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> maxl(n), minr(n);
        maxl[0] = A[0], minr[n - 1] = A[n - 1];
        
        for(int i = 1; i < n; i++) {
            maxl[i] = max(A[i], maxl[i - 1]);
            minr[n - i - 1] = min(A[n - i - 1], minr[n - i]);
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(maxl[i] <= minr[i + 1])
                return i + 1;
        }
        
        return -1;
    }
};
