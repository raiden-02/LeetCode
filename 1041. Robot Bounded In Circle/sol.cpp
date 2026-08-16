class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0; //north first
        unordered_set<string> vis = {"0,0"};
        for(char i : instructions) {
            if(i == 'G') {
                if(dir == 0)
                    y += 1;
                else if(dir == 1)
                    x -= 1;
                else if(dir == 2)
                    y -= 1;
                else if(dir == 3)
                    x += 1;
                //cout << x << " " << y << endl;
            }
            else if(i == 'L') {
                if(dir == 3)
                    dir = 0;
                else
                    dir += 1;
            }
            else {
                if(dir == 0)
                    dir = 3;
                else
                    dir -= 1;
            }
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};
