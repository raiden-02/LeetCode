class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> top, bottom, common;
        int maxtop = 0, maxbottom = 0, maxct = 0, maxcb = 0, mc = 0;
        
        
        for(int i = 0; i < tops.size(); i++) {
            top[tops[i]]++, bottom[bottoms[i]]++;
            
            if(top[tops[i]] > maxct)
                maxtop = tops[i], maxct = top[tops[i]];
            
            if(bottom[bottoms[i]] > maxcb)
                maxbottom = bottoms[i], maxcb = bottom[bottoms[i]];
            
            if(tops[i] == bottoms[i]) common[tops[i]]++;
            
            else common[tops[i]]++, common[bottoms[i]]++;
            
            mc = max(mc, max(common[tops[i]], common[bottoms[i]]));
        }
        
        
        return mc == tops.size() ? tops.size() - max(maxct, maxcb) : -1;
    }
};
