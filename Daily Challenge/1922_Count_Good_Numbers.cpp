class Solution
{
public:
    const int MOD = 1e9 + 7;

    long long power(long long x, long long y)
    {
        long long result = 1;
        x %= MOD;
        while (y > 0)
        {
            if (y % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        return (power(5, even_positions) * power(4, odd_positions)) % MOD;
    }
};
