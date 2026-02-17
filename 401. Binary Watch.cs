public class Solution {
    string format(int hours, int min) {
        string m = (min < 10) ? "0" + min.ToString() : min.ToString();
        return hours.ToString() + ":" + m;
    }

    int count_one_bits(int num) {
        int count = 0;

        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }

        return count;
    }

    public IList<string> ReadBinaryWatch(int turnedOn) {
        List<string> ans = new List<string>();

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (count_one_bits(h) + count_one_bits(m) == turnedOn)
                    ans.Add(format(h, m));
            }
        }

        return ans;
    }
}
