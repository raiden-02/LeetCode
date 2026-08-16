class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        
        while(k--)
            next_permutation(num.begin(), num.end());
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++) {
            int j = i;
           while(s[j] != num[i])
               j++;
            
            while(j != i)
                swap(s[j], s[j - 1]), j--, ans++;
        }
        
        return ans;
    }
};
