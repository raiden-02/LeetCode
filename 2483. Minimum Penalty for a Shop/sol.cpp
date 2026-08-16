class Solution {
public:
    int bestClosingTime(string customers) {
        int s = count(customers.begin(), customers.end(), 'Y');
        int ind = 0, ans = s;

        for(int i = 0; i < customers.length(); i++) {
            s -= customers[i] == 'Y';
            s += customers[i] == 'N';
            if(s < ans) {
                ind = i + 1;
                ans = s;
            }
        }

        return ind;
    }
};
