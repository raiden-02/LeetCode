class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> vis;
        pair<int, int> cur = {0, 0};
        vis.insert(cur);

        for(char x : path) {
            if(x == 'N') {
                cur.second += 1;
            }

            else if(x == 'S') {
                cur.second -= 1;
            }

            else if(x == 'E') {
                cur.first += 1;
            }

            else {
                cur.first -= 1;
            }

            if(vis.find(cur) == vis.end()) {
                vis.insert(cur);
            }

            else return true;
        }

        return false;
    }
};
