class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curgas = 0, totgas = 0, start = 0;
        
        for(int i = 0; i < cost.size(); i++) {
            int diff = gas[i] - cost[i];
            curgas += diff, totgas += diff;

            if(curgas < 0) curgas = 0, start = i + 1;
        }

        return totgas < 0 ? -1 : start;
    }
};
