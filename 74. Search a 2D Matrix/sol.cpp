class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1;
        
        while(i >= 0) {
            if(target == matrix[i][0])
                return true;
            
            if(target < matrix[i][0])
                i--;
            
            else {
                auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
                
                if(it != matrix[i].end())
                    return *it == target;
                
                return false;
            }
        }
        
        return false;
    }
};

// --- alternate solution ---

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        
        while(i >= 0 and j < n) {
            if(target > matrix[i][j])
                j++;
            
            else if(target < matrix[i][j])
                i--;
            
            else
                return true;
        }
        
        return false;
    }
};
