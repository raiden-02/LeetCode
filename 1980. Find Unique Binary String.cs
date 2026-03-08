public class Solution
{
    string ans = "";

    void Helper(int ind, int n, HashSet<string> nums, char[] s)
    {
        if (!string.IsNullOrEmpty(ans)) return; // stop once found

        if (ind >= n)
        {
            string candidate = new string(s);
            if (!nums.Contains(candidate))
            {
                ans = candidate;
            }
            return;
        }

        s[ind] = '1';
        Helper(ind + 1, n, nums, s);

        s[ind] = '0';
        Helper(ind + 1, n, nums, s);
    }

    public string FindDifferentBinaryString(string[] nums)
    {
        HashSet<string> numsSet = new HashSet<string>(nums);
        int n = nums[0].Length;

        char[] s = new string('0', n).ToCharArray();
        Helper(0, n, numsSet, s);

        return ans;
    }
}
