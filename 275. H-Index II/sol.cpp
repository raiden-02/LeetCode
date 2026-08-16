class Solution {
public:

/*
The h-index is defined as the maximum value of h such that the given author/journal has published at least h papers that have each been cited at least h times
*/
    int hIndex(vector<int>& arr) {
        int l = 0, n = arr.size(), r = n - 1;

        while(l <= r) {
            int mid = (l + r) >> 1;

            if(n - mid == arr[mid]) 
                return arr[mid];

            if(n - mid < arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return n - l;
    }
};
