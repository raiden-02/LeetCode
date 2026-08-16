class Solution:
    def judgeCircle(self, moves: str) -> bool:
        a,b,c,d = 0,0,0,0
        
        for x in moves:
            if(x == 'U'):
                a += 1
            elif(x == 'D'):
                b += 1
            elif(x == 'L'):
                c += 1
            else:
                d += 1
        
        return a == b and c == d

# --- alternate solution ---

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        dirs = {'U':(0, 1), 'R':(1, 0), 'L':(-1, 0), 'D':(0, -1)}
        
        cur, i = [0, 0], [0, 0]
        for x in moves:
            dcur = dirs[x]
            cur[0] += dcur[0]
            cur[1] += dcur[1]
        
        return cur == i
