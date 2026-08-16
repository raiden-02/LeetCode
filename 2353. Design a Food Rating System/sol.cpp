class FoodRatings {
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            foodRatingMap[foods[i]] = -ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineMap[food];
        int oldRating = foodRatingMap[food];
        cuisineFoodMap[cuisine].erase({oldRating, food});
        foodRatingMap[food] = -newRating;
        cuisineFoodMap[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineFoodMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
