public class Solution {
    public int[] PlusOne(int[] digits) {
        List<int> ans = new List<int>();
        int carry = 1;

        for (int i = digits.Length - 1; i >= 0; i--) {
            int newNum = digits[i] + carry;
            int newDig = newNum % 10;
            carry = newNum / 10;

            ans.Add(newDig);
        }

        if(carry > 0) ans.Add(carry);

        ans.Reverse();
        
        return ans.ToArray();
    }
}
