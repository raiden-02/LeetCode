class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0, rem = 0;
        do {
            rem = numBottles % numExchange;
            drank += numBottles - rem;
            numBottles = numBottles / numExchange;
            numBottles += rem;
            cout << numBottles << endl;
        } while(numBottles >= numExchange);

        return drank + numBottles;
    }
};
