//O(n)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        vector<int> diff(n);
        
        for(int i = 0; i < n; i++)
            diff[i] = abs(arr[i] - x);
        
        int ind = min_element(diff.begin(), diff.end()) - diff.begin(), l = ind, r = ind;
        
        while(r - l + 1 < k) {
            if(l - 1 >= 0 and r + 1 < n) {
                if(diff[l - 1] <= diff[r + 1]) l--;
                else r++;
            }
            
            else {
                if(l - 1 >= 0) l--;
                else r++;
            }
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
