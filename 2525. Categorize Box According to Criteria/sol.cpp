class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = (long long)length * (long long)width * (long long)height;
        bool f1 = false, f2 = false;
        long long DIM = 1e4, VOL = 1e9;
        
        if(length >= DIM or width >= DIM or height >= DIM or vol >= VOL)
            f1 = true;
        
        if(mass >= 100)
            f2 = true;
        
        if(f1 and f2) return "Both";
        
        if(not f1 and not f2) return "Neither";
        
        if(f1 and not f2) return "Bulky";
        
        if(f2 and not f1) return "Heavy";
        
        return "";
    }
};
