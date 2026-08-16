class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1, maxp = 0, profit = 0, wait = 0;
        
        for(int i = 0; i < customers.size() || wait > 0; i++) {
            if(i < customers.size())
                wait += customers[i];
            
            profit += min(4, wait) * boardingCost - runningCost; //main catch, profit can be added and not newly calculated in ever step atq
            wait -= min(4, wait);
            
            if(profit > maxp)
                ans = i + 1, maxp = profit;
        }
        
        return ans;
    }
};
