class Solution {
    private List<List<String>> ans = new ArrayList<>();
    
    private boolean isPal(String s) {
        for(int l = 0, r = s.length() - 1; l <= r; l++, r--)
            if(s.charAt(l) != s.charAt(r)) return false;
        return true;
    }
    
    private void helper(String s, int ind, List<String> tmp) {
        if(ind >= s.length()) {
            ans.add(new ArrayList<>(tmp));
            return;
        }
        
        for(int i = ind; i < s.length(); i++) {
            String left = s.substring(ind, i + 1);
            
            if(isPal(left)) {
                tmp.add(left);
                helper(s, i + 1, tmp);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        helper(s, 0, new ArrayList<>());
        return ans;
    }
}
