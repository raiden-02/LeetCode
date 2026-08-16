class Solution {
    public String decodeString(String s) {
        Stack<Character> st = new Stack<>();
        
        for(char x : s.toCharArray()) {
            st.add(x);
            
            if(x == ']') {
                st.pop();
                StringBuilder tmp = new StringBuilder();
                
                
                while(st.peek() != '[') {
                    tmp.insert(0, st.pop());
                }
                
                st.pop();
                StringBuilder num = new StringBuilder();
                
                while(!st.isEmpty() && st.peek() >= '0' && st.peek() <= '9') {
                    num.insert(0, st.pop());
                }
                
                int n;
                if(num.toString().isEmpty()) n = 1;
                else n = Integer.parseInt(num.toString());
                
                //System.out.println(n);
                
                StringBuilder cur = new StringBuilder();
                
                while(n-- > 0) {
                    cur.append(tmp); 
                }
                
                //System.out.println(cur);
                
                for(char y : cur.toString().toCharArray())
                    st.add(y);
            }
        }
        
        StringBuilder ans = new StringBuilder();
        
        while(!st.isEmpty()) 
            ans.insert(0, st.pop());
        
        return ans.toString();
    }
}
