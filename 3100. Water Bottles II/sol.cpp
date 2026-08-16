class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles, emptyBottles = 0;
        int ans = 0;

        while(fullBottles || emptyBottles >= numExchange) {
            if(emptyBottles < numExchange) {
                if(fullBottles) {
                    ans += fullBottles;
                    emptyBottles += fullBottles;
                    fullBottles = 0;
                }
            }

            else {
                fullBottles += 1;
                emptyBottles -= numExchange;
                numExchange += 1;
            }
        }

        return ans;

    }
};
