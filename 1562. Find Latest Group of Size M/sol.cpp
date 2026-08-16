class Solution {
    /*
    we maintain a counts array where counts[i] contains the no of ones existing in the group i is involved in, then whenever we find a new one, we increment the first element of the group and the last element of the merged to group to the previous counts[cur - 1] + counts[cur + 1] + 1
    */
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), ans = -1;
        
        if(m == n) return n;
        
        vector<int> counts(n + 2);
        
        for(int i = 0; i < n; i++) {
            int cur = arr[i], left = counts[cur - 1], right = counts[cur + 1];
            
            counts[cur - left] = counts[cur + right] = left + right + 1;
            
            if(left == m or right == m)
                ans = i;
        }
        
        return ans;
    }
};
