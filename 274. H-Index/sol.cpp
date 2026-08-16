class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int bucket[n + 1];
        memset(bucket, 0, sizeof(bucket));
        
        for(int x : citations) {
            if(x >= n) bucket[n]++;
            else bucket[x]++;
        }
        
        int c = 0;
        
        for(int i = n; i >= 0; i--) {
            c += bucket[i];
            if(c >= i)
                return i;
        }
        
        return 0;
    }
};
