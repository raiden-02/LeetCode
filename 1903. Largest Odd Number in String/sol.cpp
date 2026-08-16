class Solution {
public:
    string largestOddNumber(string num) {
      int i = 0;

      for(; i < num.length() && num[i] == '0'; i++);

      for(int j = num.length() - 1; j >= i; j--) {
        if((num[j] - '0') % 2 != 0) {
          return num.substr(i, j - i + 1);
        }
      }

      return "";
    }
};
