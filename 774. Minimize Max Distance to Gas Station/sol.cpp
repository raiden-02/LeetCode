class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = stations.back() - stations[0];
        
        auto possible = [&stations, &k](double distance) {
            int newStations = 0;
            
            for(int i = 0; i < stations.size() - 1; i++)
                newStations += (stations[i + 1] - stations[i]) / distance;
            
            return newStations <= k;
        };
        
        while(right - left > 1e-6) {
            double mid = left + (right - left) / 2.0;
            
            if(possible(mid))
                right = mid;
            else
                left = mid;
        }
        
        return right;
    }
};
