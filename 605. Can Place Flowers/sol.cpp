class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        
        for(int i = 0; i < m && n > 0; ) {
            if(flowerbed[i] == 0) {
                if(i == m - 1 || flowerbed[i] == flowerbed[i + 1]) n--, i += 2;
                else i++;
            }

            else if(flowerbed[i] == 1) {
                i += 2;
            }

            else i++;
        }

        return n == 0;
    }
};
