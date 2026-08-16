class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3) return false;
        
        sum /= 3;
        int l = 0, r = arr.size() - 1, s = 0;
        
        do {
            s += arr[l++];
        } while(s != sum and l < arr.size());
        
        l--, s = 0;
        
        do {
            s += arr[r--];
        } while(s != sum and r >= 0); 
        
        r++;
        
        return l < r - 1;
    }
};
