class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        bool f = true;
        vector<int> arr;
        
        while(num) {
            int r = num % 10;
            num /= 10;
            arr.push_back(r);
        }
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(f and arr[i] == 6)
                arr[i] = 9, f = false;
            ans = ans * 10 + arr[i];
        }
        
        return ans;
    }
};
