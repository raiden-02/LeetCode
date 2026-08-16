class Solution {
    double r, a, b;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        a = x_center;
        b = y_center;
    }
    
    bool plugIn(double const& x, double const& y) {
        return pow(x - a, 2) + pow(y - b, 2) <= pow(r, 2); 
    }
    
    vector<double> randPoint() {
        while(true) {
            double x = (double)rand()/RAND_MAX * (2 * r) + a - r;
            double y = (double)rand()/RAND_MAX * (2 * r) + b - r;
            if(plugIn(x, y)) return {x, y};
        }
        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
