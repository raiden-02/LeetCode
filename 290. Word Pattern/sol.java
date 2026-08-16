class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<String, Character> s2c = new HashMap<>();
        Map<Character, String> c2s = new HashMap<>();
    
        String[] ns = s.split("\\s+");
        
        int m = pattern.length(), n = ns.length;
        
        if(m != n) return false;
        
        for(int i = 0; i < m; i++) {
            if(!c2s.containsKey(pattern.charAt(i))) 
                c2s.put(pattern.charAt(i), ns[i]);
            
            else if(!c2s.get(pattern.charAt(i)).equals(ns[i]))
                return false;
            
            if(!s2c.containsKey(ns[i]))
                s2c.put(ns[i], pattern.charAt(i));
            
            else if(s2c.get(ns[i]) != pattern.charAt(i))
                return false;
        }
        
        return true;
    }
}
