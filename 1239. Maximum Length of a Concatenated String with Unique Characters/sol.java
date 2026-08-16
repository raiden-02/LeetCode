class Solution {
    private int helper(List<String> arr, int cnt[], int ind) {
        if(ind >= arr.size())
            return 0;
        
        int ans = helper(arr, cnt, ind + 1);
        String word = arr.get(ind);
        boolean f = true;
        
        for(int i = 0; i < word.length(); i++) {
            cnt[word.charAt(i) - 'a']++;
            
            if(cnt[word.charAt(i) - 'a'] > 1) {
                f = false;
            }
        }
        
        if(f) 
            ans = Math.max(ans, (int)word.length() + helper(arr, cnt, ind + 1));
        
        for(int i = 0; i < word.length(); i++) {
            cnt[word.charAt(i) - 'a']--;
        }
        
        return ans;
    }
    public int maxLength(List<String> arr) {
        int cnt[] = new int[26];
        return helper(arr, cnt, 0);
    }
}
