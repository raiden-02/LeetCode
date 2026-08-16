class Solution {
    int getmaxsum(vector<int> &arr, int const& k) {
        multiset<int> sortedSum;
        int ans = INT_MIN, s = 0;
        sortedSum.insert(0);
        
        for(int &x : arr) {
            s += x;
            auto ind = sortedSum.lower_bound(s - k);
            
            if(ind != sortedSum.end())
                ans = max(ans, s - *ind);
            
            if(ans == k) break;
            
            sortedSum.insert(s);
        }
        
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MIN;
    
       for(int col1 = 0; col1 < n; col1++) {
           vector<int> arr(m);
           
           for(int col2 = col1; col2 < n; col2++) {
               for(int i = 0; i < m; i++)
                   arr[i] += matrix[i][col2];
               
               ans = max(ans, getmaxsum(arr, k));
               
               if(ans == k) return k;
           }
        }
        
        return ans;
    }
};
