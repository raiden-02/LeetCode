class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx <= tx and sy <= ty) {
            if(tx > ty) {
                if(tx % ty == sx % ty and sy == ty)
                    return true;
                tx = tx % ty;
            }
            
            else {
                if(ty % tx == sy % tx and sx == tx)
                    return true;
                ty = ty % tx;
            }
        }
        
        return false;
    }
};
