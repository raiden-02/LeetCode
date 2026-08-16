class Solution {
public:
    int kthGrammar(int n, int k) {
        int num = k - 1;
        int cnt = 0;

        while(num) {
            cnt += num & 1;
            num >>= 1;    
        }

        return cnt % 2 == 0 ? 0 : 1;
    }
};
