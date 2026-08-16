class UndergroundSystem {
    unordered_map<int, pair<string, int>> ci;
    unordered_map<string, vector<double>> co;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ci[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        co[ci[id].first + ":" + stationName].push_back(t - ci[id].second); 
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<double> vec = co[startStation + ":" + endStation];
        double ans = 0, n = vec.size();
        for(double &i : vec)
            ans += i;
        return ans / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
