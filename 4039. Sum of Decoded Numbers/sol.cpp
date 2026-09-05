class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long base, long long exponent) {
        long long result = 1;
        base %= MOD;

        while (exponent > 0) {
            if (exponent % 2 != 0) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exponent >>= 1;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for (long long num : nums) {
            int width = num % 10;
            string digits = to_string(num / 10);

            string xs = digits.substr(0, width);
            string ys = digits.substr(width);

            long long x = stoll(xs);
            long long y = stoll(ys);

            long long decoded = modPow(x, y);
            ans = (ans + decoded) % MOD;
        }

        return static_cast<int>(ans);
    }
};
