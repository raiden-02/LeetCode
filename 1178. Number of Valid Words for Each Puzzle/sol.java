class Solution {
    private int bitmask(String word) {
        int mask = 0;
        
        for(char x : word.toCharArray())
            mask |= 1 << (x - 'a');
        
        return mask;
    }
    
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> wordMap = new HashMap<>();
        
        for(String word : words) {
            int mask = bitmask(word);
            wordMap.put(mask, wordMap.getOrDefault(mask, 0) + 1);
        }
        
        List<Integer> ans = new ArrayList<>();
        
        for(String puzzle : puzzles) {
            int first = 1 << (puzzle.charAt(0) - 'a');
            int count = wordMap.getOrDefault(first, 0);
            
            int mask = bitmask(puzzle.substring(1));
            
            for(int submask = mask; submask > 0; submask = (submask - 1) & mask)
                count += wordMap.getOrDefault(submask | first, 0);
            
            ans.add(count);
        }
        
        return ans;
    }
}
