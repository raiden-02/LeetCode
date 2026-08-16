class Solution {
    //same as leetcode 31 next permutation
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        auto ind = is_sorted_until(s.rbegin(), s.rend());
        
        if(ind != s.rend())
            swap(*ind, *upper_bound(s.rbegin(), ind, *ind));
        
        reverse(s.rbegin(), ind);
        
        int ans = stoll(s);
        
        return ans > n ? ans : -1;
    }
};
