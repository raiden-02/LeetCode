class SnakeGame {
    vector<vector<int>> foods;
    pair<int, int> cur = {0, 0};
    int m, n, i;
    deque<pair<int, int>> q;
    set<pair<int, int>> visbody;
    unordered_map<string, pair<int, int>> mp = {{"U", {-1, 0}}, {"D", {1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}};
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        foods = food;
        m = height, n = width, i = 0;
        q.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto cur = q.back();
        auto rem = q.front(); q.pop_front();
        visbody.erase(rem);
        
        cur.first += mp[direction].first;
        cur.second += mp[direction].second;
        
        if(cur.first >= m or cur.first < 0 or cur.second >= n or cur.second < 0 or visbody.find(cur) != visbody.end())
            return -1;
        
        visbody.insert(cur);
        q.push_back(cur);
        
        if(i >= foods.size())
            return q.size() - 1;
        
        if(cur.first == foods[i][0] and cur.second == foods[i][1]) {
            q.push_front(rem);
            visbody.insert(rem);
            i++;
        }
        
        return q.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
