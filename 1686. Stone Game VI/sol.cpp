class Solution {
    /*For n=2, we have [a1,a2], [b1,b2]
    For Alice, she can choose a1, so the diff is a1-b2, or choose a2, gets a2-b1
    for alice to win her choice should be much higher than bob's choice therefore,  to           select between stones 1 and 2 she looks for a1 - b2 > a2 - b1 => a1 + b1 > a2 + b2*/
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<array<int, 3>> sumarr(n);
        
        for(int i = 0; i < n; i++)
            sumarr[i] = {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]};
        
        sort(sumarr.rbegin(), sumarr.rend()); //sort in descending
        
        int a = 0, b = 0;
        
        for(int i = 0; i < n; i++) {
            a += i % 2 == 0 ? sumarr[i][1] : 0;
            b += i % 2 ? sumarr[i][2] : 0;
        }
        
        return a == b ? 0 : a > b ? 1 : -1;
    }
};
