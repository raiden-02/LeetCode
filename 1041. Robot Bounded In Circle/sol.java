class Solution {
    public boolean isRobotBounded(String instructions) {
        int x = 0, y = 0, dir = 0;
        
        for(int i = 0; i < instructions.length(); i++) {
            char cur = instructions.charAt(i);
            
            if(cur == 'G') {
                if(dir == 0) y++;
                else if(dir == 1) x++;
                else if(dir == 2) y--;
                else x--;
            }
            
            else if(cur == 'L') dir = (dir - 1) % 4;
            else dir = (dir + 1) % 4;
            
            if(dir < 0) dir += 4;
        }
        
        return (x == 0 && y == 0) || dir != 0;
    }
}
