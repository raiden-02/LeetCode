class Vector2D {
    queue<int> arr;
public:
    Vector2D(vector<vector<int>>& vec) {
        for(auto &x : vec) for(int y : x) arr.push(y);
    }
    
    int next() {
        int ret = arr.front(); arr.pop();
        return ret;
    }
    
    bool hasNext() {
        return not arr.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
