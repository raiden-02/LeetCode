class StockPrice {
    int currentTime, currentPrice;
    unordered_map<int, int> tp;
    map<int, int> prices;
public:
    StockPrice() {
        currentTime = INT_MIN;
    }
    
    void update(int timestamp, int price) {
        if(tp.count(timestamp)) {
            int prevp = tp[timestamp];
            prices[prevp]--;

            if(prices[prevp] == 0)
                prices.erase(prevp);
        }

        tp[timestamp] = price;
        prices[price]++;
        if(currentTime <= timestamp)
            currentTime = timestamp, currentPrice = price;
    }
    
    int current() {
        return currentPrice;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
